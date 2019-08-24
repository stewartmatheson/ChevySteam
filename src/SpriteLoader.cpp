#pragma once 

#include "SpriteLoader.h"

#include <iostream>
#include <vector>
#include <fstream>

void SpriteLoader::extractPixelData(SpriteDataRow& row, std::ifstream& reader, int start, int end) {
	for (int i = start; i < end; i++) {
		PixelData pixel_data;
		uint8_t single_pixel_data = 0;
		reader.seekg(i, std::ios::beg);
		reader.read((char*)single_pixel_data, 1);

		// Get cols with a bit mask
		pixel_data.row = (single_pixel_data >> 4) & 15;
		pixel_data.col = single_pixel_data & 15;
	}
}

int SpriteLoader::load() {

	const int header_size = 2;

	std::ifstream large;
	std::string file_path = "C:\\code\\stew-city\\data\\WIN95\\WIN95\\SC2K\\DATA\\LARGE.DAT";

	large.open(file_path, std::ios::binary);
	// Seek past header
	large.seekg(0, std::ios::beg);
	unsigned short file_entries = 0;
	large.read((char*)&file_entries, sizeof(unsigned short));
	file_entries = _byteswap_ushort(file_entries);

	std::vector<Sprite> sprites;
	for (int current_header_offset = header_size; current_header_offset < file_entries; current_header_offset += 10) {
		unsigned short current_id = 0;
		large.seekg(current_header_offset, std::ios::beg);
		large.read(reinterpret_cast<char *>(&current_id), sizeof(unsigned short));

		unsigned long current_start_offset = 0;
		large.seekg(current_header_offset + 2, std::ios::beg);
		large.read(reinterpret_cast<char *>(&current_start_offset), 4);

		unsigned short current_height = 0;
		large.seekg(current_header_offset + 6, std::ios::beg);
		large.read(reinterpret_cast<char *>(&current_height), 2);

		unsigned short current_width = 0;
		large.seekg(current_header_offset + 8, std::ios::beg);
		large.read(reinterpret_cast<char *>(&current_width), 2);

		Sprite sprite;
		sprite.id = _byteswap_ushort(current_id);
		sprite.height = _byteswap_ushort(current_height);
		sprite.width = _byteswap_ushort(current_width);
		sprite.start_offset = _byteswap_ulong(current_start_offset);

		readSpriteData(sprite, large);
		sprites.push_back(sprite);
	}
	return 0;
}

void SpriteLoader::readSpriteData(Sprite& sprite, std::ifstream& reader) {
	for (int current_row_index = 0; current_row_index < sprite.height; current_row_index++) {
		SpriteDataRow sprite_data_row;
		reader.seekg(sprite.start_offset + 1, std::ios::beg);
		reader.read((char*)sprite_data_row.mode, 1);

		// TODO : We might need to move this out
		if (sprite_data_row.mode == 3 || sprite_data_row.mode == 4) {
			reader.seekg(sprite.start_offset, std::ios::beg);
			reader.read((char*)sprite_data_row.pixels_from_edge, 1);

			reader.seekg(sprite.start_offset + 2, std::ios::beg);
			reader.read((char*)sprite_data_row.pixels_in_row, 1);

			reader.seekg(sprite.start_offset + 3, std::ios::beg);
			reader.read((char*)sprite_data_row.unknown_infomation, 1);

			extractPixelData(
				sprite_data_row,
				reader,
				sprite.start_offset + 6,
				sprite.start_offset + 6 + sprite_data_row.pixels_in_row
			);
		}

		if (sprite_data_row.mode == 4) {
			reader.seekg(sprite.start_offset, std::ios::beg);
			reader.read((char*)sprite_data_row.pixels_in_row, 1);

			extractPixelData(
				sprite_data_row,
				reader,
				sprite.start_offset + 2,
				sprite.start_offset + 2 + sprite_data_row.pixels_in_row
			);
		}
	}
}



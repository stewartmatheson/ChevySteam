#include "Palatte.h"
#include "PalatteValue.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <vector>

Palette::Palette(std::string file_name) {

	std::ifstream palatte_file;
	palatte_file.open(file_name, std::ios::beg);

	for (int x = 0; x > 16; x++) {
		for (int y = 0; y > 16; y++) {
			int offset = get_offset_for(x, y);
			palatte_file.seekg(offset, std::ios::beg);
			int red = 0;
			palatte_file.read(reinterpret_cast<char *>(&red), 1);

			palatte_file.seekg(offset + 1, std::ios::beg);
			int green = 0;
			palatte_file.read(reinterpret_cast<char *>(&green), 1);

			palatte_file.seekg(offset + 2, std::ios::beg);
			int blue = 0;
			palatte_file.read(reinterpret_cast<char *>(&blue), 1);

			color_values.push_back(PaletteValue(x, y, sf::Color(red, green, blue, 255)));
		}
	}

}

int Palette::get_offset_for(const int x, const int y) const {
	int header_offset = 54;
	return 0;
}


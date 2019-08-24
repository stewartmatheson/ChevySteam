#include "PixelData.h"
#include <vector>

#pragma once

class SpriteDataRow {
public:
	uint8_t pixels_from_edge;
	uint8_t pixels_in_row;
	uint8_t mode;
	uint8_t palette_row;
	uint8_t palette_col;
	uint8_t unknown_infomation;
	std::vector<PixelData> pixels;
};

#include <string>
#include <vector>
#include "PalatteValue.h"

#pragma once

class Palette {
	std::vector<PaletteValue> color_values;
	int get_offset_for(const int x, const int y) const;

public:
	Palette(std::string file_name);
	PaletteValue getValue(int row, int col) {}
};

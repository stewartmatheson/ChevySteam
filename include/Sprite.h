
#include "SpriteDataRow.h"
#include <vector>

#pragma once

class Sprite {
public:
	unsigned short id;
	unsigned short height;
	unsigned short width;
	unsigned long start_offset;
	std::vector<SpriteDataRow> rows;
};
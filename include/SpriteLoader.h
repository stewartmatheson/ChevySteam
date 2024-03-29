
#include <iostream>
#include "SpriteDataRow.h"
#include "Sprite.h"

#pragma once

class SpriteLoader {
	
	void readSpriteData(Sprite& sprite, std::ifstream& reader);
	void extractPixelData(SpriteDataRow& row, std::ifstream& reader, int start, int end);
public:
	int load();
};

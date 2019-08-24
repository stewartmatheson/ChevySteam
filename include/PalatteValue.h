#include <SFML/Graphics.hpp>

#pragma once

class PaletteValue {
	int row;
	int col;
	sf::Color color;
public:
	PaletteValue(int row, int col, sf::Color color);
};
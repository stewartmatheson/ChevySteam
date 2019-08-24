
#include "Palatte.h"
#include <SFML/Graphics.hpp>

PaletteValue::PaletteValue(int row, int col, sf::Color color) {
	this->row = row; this->col = col; this->color = color;
}

/*
 * Tile.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: A.Melachuri
 */

#include "Tile.h"

Tile::Tile() {
	collision = false;
	sprite.setTexture(Textures::forestSheet);
	sprite.setTextureRect(IntRect(17,0,16,16));
	this->setScale(3, 3);
	id = 0;
}

Tile::~Tile() {

}


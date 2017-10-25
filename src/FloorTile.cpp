/*
 * FloorTile.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: A.Melachuri
 */

#include "FloorTile.h"

FloorTile::FloorTile() {
	sprite.setTexture(Textures::roguelikeSheet);
	sprite.setTextureRect(IntRect(102,51,16,16));
	id = 3;
}

FloorTile::~FloorTile() {
	// TODO Auto-generated destructor stub
}


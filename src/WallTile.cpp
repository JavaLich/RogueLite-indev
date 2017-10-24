/*
 * WallTile.cpp
 *
 *  Created on: Jun 24, 2017
 *      Author: A.Melachuri
 */

#include "WallTile.h"

WallTile::WallTile() {
	sprite.setTexture(Textures::roguelikeSheet);
	sprite.setTextureRect(IntRect(119,68,16,16));
	id = 2;
	collision = true;
}

WallTile::~WallTile() {
	// TODO Auto-generated destructor stub
}


/*
 * GrassTile.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: A.Melachuri
 */

#include "GrassTile.h"

GrassTile::GrassTile() {
	sprite.setTexture(Textures::forestSheet);
	sprite.setTextureRect(IntRect(0,0,16,16));
	id = 1;
}

GrassTile::~GrassTile() {
}


/*
 * Tile.h
 *
 *  Created on: Apr 12, 2017
 *      Author: A.Melachuri
 */

#include <SFML/Graphics.hpp>
#include "Textures.h"
#include <iostream>

using namespace std;
using namespace sf;

#ifndef SRC_TILE_H_
#define SRC_TILE_H_

class Tile : public sf::Transformable{
public:
	Tile();
	virtual ~Tile();
	Sprite sprite;
	bool collision;
	int id;
};

#endif /* SRC_TILE_H_ */

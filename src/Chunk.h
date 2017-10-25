/*
 * Chunk.h
 *
 *  Created on: Apr 12, 2017
 *      Author: A.Melachuri
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "WallTile.h"
#include "GrassTile.h"
#include "Tile.h"

#ifndef SRC_CHUNK_H_
#define SRC_CHUNK_H_

class Chunk {
public:
	Chunk(sf::Vector2i pos);
	bool isInWindow(sf::RenderWindow& window);
	virtual ~Chunk();
	Tile tiles[100][100];
	sf::Vector2i position;
};

#endif /* SRC_CHUNK_H_ */

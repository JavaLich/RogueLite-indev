/*
 * World.h
 *
 *  Created on: Apr 12, 2017
 *      Author: A.Melachuri
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Tile.h"
#include "GrassTile.h"
#include "WallTile.h"
#include "FloorTile.h"
#include "Chunk.h"
#include "Room.h"
#include "Dungeon.h"
#include "math.h"


#ifndef SRC_WORLD_H_
#define SRC_WORLD_H_

class World {
public:
	World();
	virtual ~World();
	unsigned int width, height;
	int tiles[100][100];
	Tile tileId[25];
	std::vector<Room> rooms;
	std::vector<Dungeon> duns;
	void createRooms(int count);
	void BSP(int count);
	void hCorridor(int x1, int x2, int y);
	void vCorridor(int y1, int y2, int x);
	void renderWorld(sf::RenderWindow& window, int boundx, int boundy);
	void createRooms2(int count);
	void createRoom(int x, int y, int width, int height);
	void calculateRoom(int xr, int yr, int wr, int hr);
	Room getClosestRoom(int index);
	bool isTileNextTo(int x, int y, int tile);
	void cleanUp();
	//class enum Direction{NORTH=0, SOUTH=1, WEST=2, EAST=3};

};

#endif /* SRC_WORLD_H_ */

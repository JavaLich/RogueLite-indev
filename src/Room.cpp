/*
 * Room.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: A.Melachuri
 */

#include "Room.h"
#include <math.h>

Room::Room(int x, int y, int w, int h) {
	//grid coords
	x1 = x;
	y1 = y;
	x2 = x + w;
	y2 = y + h;
	width = w;
	height = h;
	//Pixel coords
	pos.x = x * 48;
	pos.y = y * 48;
	size.x = w;
	size.y = h;
	centerx = floor((x1+x2)/2);
	centery = floor((y1+y2)/2);
}
bool Room::intersects(Room room){
	return (x1 <= room.x2 && x2 >= room.x1 && y1 <= room.y2 && room.y2 >= room.y1);
}

Room::~Room() {
	// TODO Auto-generated destructor stub
}


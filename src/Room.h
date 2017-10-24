/*
 * Room.h
 *
 *  Created on: Jun 25, 2017
 *      Author: A.Melachuri
 */

#ifndef SRC_ROOM_H_
#define SRC_ROOM_H_
#include <SFML/Graphics.hpp>

class Room {
public:
	Room(int x, int y, int w, int h);
	virtual ~Room();
	int x1, x2, y1, y2;
	int width, height;
	int centerx, centery;
	sf::Vector2i pos;
	sf::Vector2i size;
	bool connected=false;
	bool intersects(Room room);

};

#endif /* SRC_ROOM_H_ */

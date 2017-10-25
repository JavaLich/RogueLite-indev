/*
 * Dungeon.h
 *
 *  Created on: Jun 27, 2017
 *      Author: A.Melachuri
 */

#ifndef SRC_DUNGEON_H_
#define SRC_DUNGEON_H_

class Dungeon {
public:
	int x, y, width, height, t;
	Dungeon(int x, int y, int width, int height, int t);
	virtual ~Dungeon();
	Dungeon split(int h);
};

#endif /* SRC_DUNGEON_H_ */

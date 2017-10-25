/*
 * Dungeon.cpp
 *
 *  Created on: Jun 27, 2017
 *      Author: A.Melachuri
 */

#include "Dungeon.h"

Dungeon::Dungeon(int x, int y, int width, int height, int t) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->t = t;
}

Dungeon Dungeon::split(int h){
	t++;
	Dungeon sub(0,0,0,0,0);
	if(h==1){
		height /= 2;
		sub = Dungeon(x, y+height, width, height, t+1);
	}else{
		width /= 2;
		sub = Dungeon(x+width, y, width, height, t+1);
	}

	return sub;
}

Dungeon::~Dungeon() {
	// TODO Auto-generated destructor stub
}


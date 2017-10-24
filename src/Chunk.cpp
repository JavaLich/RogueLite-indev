/*
 * Chunk.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: A.Melachuri
 */

#include "Chunk.h"

Chunk::Chunk(sf::Vector2i pos) {
	position = pos;
	for(int y = 0; y<100;y++){
		for(int x = 0; x<100; x++){
			if(x==0) tiles[x][y] = WallTile();
			else tiles[x][y] = GrassTile();
			Tile &tile = tiles[x][y];
			tile.setPosition(x*48+(pos.x*100*48), y*48+(pos.y*100*48));
		}
	}
}

bool Chunk::isInWindow(sf::RenderWindow& window){
	Vector2i topLeft=window.mapCoordsToPixel(tiles[0][0].getPosition());
	Vector2i topRight=window.mapCoordsToPixel(tiles[99][0].getPosition());
	Vector2i bottomLeft=window.mapCoordsToPixel(tiles[0][99].getPosition());
	Vector2i bottomRight=window.mapCoordsToPixel(tiles[99][99].getPosition());
	if((topLeft.x+0>0||topLeft.x-0<window.getSize().x||topLeft.y+0>0||topLeft.y-0<window.getSize().y)||(topRight.x+0>0||topRight.x-0<window.getSize().x||topRight.y+0>0||topRight.y-0<window.getSize().y)){
		return true;
	}
	if((bottomLeft.x+0>0||bottomLeft.x-0<window.getSize().x||bottomLeft.y+0>0||bottomLeft.y-0<window.getSize().y)||(bottomRight.x+0>0||bottomRight.x-0<window.getSize().x||bottomRight.y+0>0||bottomRight.y-0<window.getSize().y)){
		return true;
	}

	cout << "Top left: " <<topLeft.x << ", " << topLeft.y << endl;
	cout << "Top right: "<<topRight.x<<", " << topRight.y << endl;


	return false;
}

Chunk::~Chunk() {

}


/*
 * World.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: A.Melachuri
 */

#include "World.h"

World::World() {
	tileId[0] = Tile();
	tileId[1] = GrassTile();
	tileId[2] = WallTile();
	tileId[3] = FloorTile();
	width = 100;
	height = 100;
	for (unsigned int y = 0; y < width; y++) {
		for (unsigned int x = 0; x < height; x++) {
			tiles[x][y] = 2;
		}
	}
	srand(time(NULL));
	//BSP(4);
	createRooms(30);
	cleanUp();
}

void World::cleanUp() {
	for (unsigned int y = 0; y < width; y++) {
		for (unsigned int x = 0; x < height; x++) {
			if (!isTileNextTo(x, y, 3)) {
				tiles[x][y] = 1;
			}

		}
	}
}

void World::createRooms2(int count) {
	int xr = 46, yr = 46, wr = 7, hr = 7;
	createRoom(46, 46, 7, 7);
	for (int i = 0; i < count; i++) {
		int random = rand() % 4;
		int length = (rand() % 7) + 4;
		//North:0
		//South:1
		//West:2
		//East:3
		random = 2;
		cout << random << endl;
		cout << "length: " << length << endl;
		int roomh, roomy, roomx, roomw;
		if (random == 3) {

			roomw = (rand() % 7) + 7;
			//roomy = (int) (rand() % (wr - 2)) + (yr + 1) - ((int) roomh / 2);
			roomy = yr;
			cout << "roomy: " << roomy << ", yr: " << yr << endl;
			roomh = 7 + (rand() % 7);
			roomx = (xr + (wr - 1) + length);
			createRoom(roomx, roomy, roomw, roomh);
			hCorridor(xr + (wr - 1), xr + (wr - 1) + length,
					(int) (rand() % (wr - 2)) + (yr + 1));

		} else if (random == 2) {
			roomw = (rand() % 7) + 7;
			//roomy = (int) (rand() % (wr - 2)) + (yr + 1) - ((int) roomh / 2);
			roomy = yr;
			roomh = (rand() % 7) + 7;
			roomx = xr - length - roomw;
			createRoom(roomx, roomy, roomw, roomh);
			hCorridor(xr - length, xr + 1,
					(int) (rand() % (wr - 2)) + (yr + 1));

		} else if (random == 1) {

			vCorridor(yr + (hr - 1), yr + (hr - 1) + length,
					(int) (rand() % (hr - 2)) + (xr + 1));
		} else if (random == 0) {
			vCorridor(yr - length, yr + 1,
					(int) (rand() % (hr - 2)) + (xr + 1));
		}
		calculateRoom(roomx, roomy, roomw, roomh);
	}
}

void World::calculateRoom(int xr, int yr, int wr, int hr) {
	int random = rand() % 4;
	int length = (rand() % 7) + 4;
	random = 2;
	if (random == 3) {

		int roomh = (rand() % 7) + 7;
		int roomy = (int) (rand() % (wr - 2)) + (yr + 1) - ((int) roomh / 2);
		createRoom((xr + (wr - 1) + length), roomy, roomh, 7 + (rand() % 7));
		hCorridor(xr + (wr - 1), xr + (wr - 1) + length,
				(int) (rand() % (wr - 2)) + (yr + 1));

	} else if (random == 2) {
		int roomh = (rand() % 7) + 7;
		int roomy = (int) (rand() % (wr - 2)) + (yr + 1) - ((int) roomh / 2);
		int roomw = 7 + (rand() % 7);
		createRoom(xr - length - roomw, roomy, roomh, roomw);
		hCorridor(xr - length, xr + 1, (int) (rand() % (wr - 2)) + (yr + 1));

	} else if (random == 1) {
		vCorridor(yr + (hr - 1), yr + (hr - 1) + length,
				(int) (rand() % (hr - 2)) + (xr + 1));
	} else if (random == 0) {
		vCorridor(yr - length, yr + 1, (int) (rand() % (hr - 2)) + (xr + 1));
	}
}

void World::createRoom(int x, int y, int width, int height) {
	Room room = Room(x, y, width, height);
	for (int y = room.y1; y < room.y2; y++) {
		for (int x = room.x1; x < room.x2; x++) {
			tiles[x][y] = 3;
//			if (x == room.x1 || x == room.x2 - 1 || y == room.y1
//					|| y == room.y2 - 1) {
//				tiles[x][y] = 2;
//			}
		}
	}
}

void World::BSP(int count) {
	duns.push_back(Dungeon(0, 0, 100, 100, 1));
	for (int i = 0; i < count; i++) {
		duns.push_back(duns.at(i));
		if (rand() % 1 == 0) {
			duns.push_back(duns.at(i).split(1));
		} else {
			duns.push_back(duns.at(i).split(0));
		}
	}
	for (int j = 0; j < duns.size(); j++) {
		int w = (rand() % (duns.at(j).width - 3)) + 3;
		int h = (rand() % (duns.at(j).height - 3)) + 3;
		int x = (rand() % (duns.at(j).width - w)) + duns.at(j).x;
		int y = (rand() % (duns.at(j).height - h)) + duns.at(j).y;
		Room room = Room(x, y, w, h);
		for (int y = room.y1; y < room.y2; y++) {
			for (int x = room.x1; x < room.x2; x++) {
				tiles[x][y] = 3;
			}
		}
	}
}

void World::hCorridor(int x1, int x2, int y) {
	//cout << "x: " << x1 << ", x2: " << x2 << ", y: " << y << ", h" << endl;
	for (int x = x1; x < x2; x++) {
		//tiles[x][y - 1] = 3;
		tiles[x][y] = 3;
		//tiles[x][y + 1] = 3;
	}
	//tiles[x2][y] = 3;
	//tiles[x1 - 1][y] = 3;
}

void World::vCorridor(int y1, int y2, int x) {
	//cout << "x: " << x << ", y: " << y1 << ", y2: " << y2 << ", v" << endl;

	for (int y = y1; y < y2; y++) {
		//tiles[x - 1][y] = 3;
		tiles[x][y] = 3;
		//tiles[x + 1][y] = 3;
	}
}

void World::createRooms(int count) {
	sf::Vector2i newCenter;
	sf::Vector2i prevCenter;
	for (int i = 0; i < count; i++) {
		int w = (rand() % 5) + 7;
		int h = (rand() % 5) + 7;
		int x = (rand() % (100 - w)) + 1;
		int y = (rand() % (100 - h)) + 1;
		Room room = Room(x, y, w, h);
		bool failed = false;
		for (int j = 0; j < rooms.size(); j++) {
			if (room.intersects(rooms.at(j))) {
				failed = true;
				break;
			}
		}
		if (!failed) {
			createRoom(x, y, w, h);
			newCenter = sf::Vector2i(room.centerx, room.centery);

			if (rooms.size() != 0) {
				sf::Vector2i prevCenter = sf::Vector2i(
						rooms.at(rooms.size() - 1).centerx,
						rooms.at(rooms.size() - 1).centery);
//				if (rand() % 2 == 1) {
//					if (newCenter.x < prevCenter.x)
//						hCorridor(newCenter.x, prevCenter.x, prevCenter.y);
//					else
//						hCorridor(prevCenter.x, newCenter.x, prevCenter.y);
//					if (newCenter.y < prevCenter.y)
//						vCorridor(newCenter.y, prevCenter.y, newCenter.x);
//					else
//						vCorridor(prevCenter.y, newCenter.y, newCenter.x);
//				} else {
//					if (prevCenter.y < newCenter.y)
//						vCorridor(prevCenter.y, newCenter.y, prevCenter.x);
//					else
//						vCorridor(newCenter.y, prevCenter.y, prevCenter.x);
//					if (prevCenter.x < newCenter.x)
//						hCorridor(prevCenter.x, newCenter.x, newCenter.y);
//					else
//						vCorridor(newCenter.x, prevCenter.x, newCenter.y);
//				}
				if (newCenter.x < prevCenter.x)
					hCorridor(newCenter.x, prevCenter.x, prevCenter.y);
				else
					hCorridor(prevCenter.x, newCenter.x+1, prevCenter.y);
				if (newCenter.y < prevCenter.y)
					vCorridor(newCenter.y, prevCenter.y, newCenter.x);
				else
					vCorridor(prevCenter.y, newCenter.y, newCenter.x);
				//tiles[prevCenter.x][prevCenter.y]=1;
				//cout<< "X: " << prevCenter.x << ", Y: "<<prevCenter.y<<endl;
			}
			rooms.push_back(room);
		}
		//cout<< "Size: "<<rooms.size()<<endl;
	}
//
//	for(int i = 0; i<rooms.size();i++){
//		Room room = rooms.at(i);
//		if(!room.connected){
//			Room r2 = getClosestRoom(i);
//			tiles[r2.centerx][r2.centery]=rand()%4;
//			tiles[room.centerx][room.centery]=tiles[r2.centerx][r2.centery];
//		}
//	}

	cout << "end of loop" << endl;
}

bool World::isTileNextTo(int x, int y, int tile) {
	if (tiles[x - 1][y] == tile || tiles[x - 1][y - 1] == tile
			|| tiles[x][y - 1] == tile|| tiles[x + 1][y - 1] == tile
			|| tiles[x + 1][y] == tile || tiles[x + 1][y + 1] == tile
			|| tiles[x][y + 1] == tile || tiles[x - 1][y + 1] == tile)return true;

	else return false;


}

Room World::getClosestRoom(int index) {
	int distx = 1000, disty = 1000;
	Room closestRoom(0, 0, 0, 0);
	int oldDist = (int) sqrt(
			(rooms.at(index).centerx - distx)
					* (rooms.at(index).centerx - distx)
					+ (rooms.at(index).centery - disty)
							* (rooms.at(index).centery - disty));
	for (int i = 0; i < rooms.size(); i++) {
		if (i != index) {
			int currx = rooms.at(i).centerx - rooms.at(index).centerx;
			int curry = rooms.at(i).centery - rooms.at(index).centery;
			int dist = (int) sqrt((currx) * (currx) + (curry) * (curry));
			if (dist < oldDist) {
				oldDist = dist;
				closestRoom = rooms.at(i);
			}
		}
	}
	return closestRoom;
}

void World::renderWorld(sf::RenderWindow &window, int boundx, int boundy) {
	for (unsigned int x = 0; x < width; x++) {
		for (unsigned int y = 0; y < height; y++) {
			sf::Vector2i windowCoords = window.mapCoordsToPixel(
					sf::Vector2f(x * 48, y * 48));
			if (windowCoords.x > -48 && windowCoords.x < boundx + 0
					&& windowCoords.y > -48 && windowCoords.y < boundy + 0) {
				tileId[tiles[x][y]].setPosition(x * 48, y * 48);
				window.draw(tileId[tiles[x][y]].sprite,
						tileId[tiles[x][y]].getTransform());
			}
		}
	}
}

World::~World() {
	// TODO Auto-generated destructor stub
}


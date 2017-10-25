/*
 * GrassTile.h
 *
 *  Created on: Apr 12, 2017
 *      Author: A.Melachuri
 */

#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <iostream>

using namespace std;
using namespace sf;

#ifndef SRC_GRASSTILE_H_
#define SRC_GRASSTILE_H_

class GrassTile : public Tile {
public:
	GrassTile();
	virtual ~GrassTile();
};

#endif /* SRC_GRASSTILE_H_ */`

/*
 * Textures.h
 *
 *  Created on: Apr 12, 2017
 *      Author: A.Melachuri
 */

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#ifndef SRC_TEXTURES_H_
#define SRC_TEXTURES_H_

class Textures {
public:
	Textures();
	virtual ~Textures();
	static Texture forestSheet;
	static Texture grass;
	static Texture voidTile;
	static Texture playerSheet;
	static Texture roguelikeSheet;
};

#endif /* SRC_TEXTURES_H_ */

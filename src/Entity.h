/*
 * Entity.h
 *
 *  Created on: Apr 29, 2017
 *      Author: A.Melachuri
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include "World.h"

using namespace std;
using namespace sf;

#ifndef SRC_ENTITY_H_
#define SRC_ENTITY_H_

class Entity : public Transformable{
public:
	Entity();
	Entity(Vector2f pos, World* w);
	void update();
	virtual ~Entity();
	bool collision();
	Vector2i getTilePos();
	Sprite sprite;
	World *world;
	Vector2f deltaPos;
	Vector2f futurePos;
};

#endif /* SRC_ENTITY_H_ */

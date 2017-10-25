/*
 * Player.h
 *
 *  Created on: Apr 29, 2017
 *      Author: A.Melachuri
 */

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Textures.h"
#include "Entity.h"

using namespace std;
using namespace sf;

#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

class Player : public Entity{
public:
	Player(Vector2f pos, World *w) : Entity(pos, w){
		sprite.setTexture(Textures::forestSheet);
		sprite.setTextureRect(IntRect(0,32,16,16));
		this->setScale(2, 2);
	}
	void update();
	bool collision(float dx, float dy);
	virtual ~Player();
	Sprite sprite;

};

#endif /* SRC_PLAYER_H_ */

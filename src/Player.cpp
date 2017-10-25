/*
 * Player.cpp
 *
 *  Created on: Apr 29, 2017
 *      Author: A.Melachuri
 */

#include "Player.h"

void Player::update() {
	deltaPos = Vector2f(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		deltaPos.y -= 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		deltaPos.y += 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		deltaPos.x -= 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		deltaPos.x += 5;
	}

//	futurePos = Vector2f(this->getPosition().x+deltaPos.x, this->getPosition().y+deltaPos.y);
	if (!collision(0, deltaPos.y))
		this->move(0, this->deltaPos.y);
	if (!collision(deltaPos.x, 0))
		this->move(this->deltaPos.x, 0);

//	cout << "X: " << this->getTilePos().x << ", Y:"<<this->getTilePos().y<<endl;
}

bool Player::collision(float dx, float dy) {
	bool collision = false;
	for (int i = 0; i < 4; i++) {
		int xl = (int) (((this->getPosition().x + dx)+i % 2 * 27 + 2) / 48);
		int yl = (int) (((this->getPosition().y + dy)+i / 2 * 27 + 3) / 48);
		if (world->tileId[world->tiles[xl][yl]].collision)
			collision = true;
	}
	return collision;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}


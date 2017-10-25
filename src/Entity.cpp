/*
 * Entity.cpp
 *
 *  Created on: Apr 29, 2017
 *      Author: A.Melachuri
 */

#include "Entity.h"

Entity::Entity() {

}

Entity::Entity(Vector2f pos, World* w){
	this->setPosition(pos);
	deltaPos.x=0;
	deltaPos.y=0;
	this->world=w;
}


void Entity::update(){

}

bool Entity::collision(){
	return false;
}

Vector2i Entity::getTilePos(){
	Vector2i tilePos = Vector2i((int)this->getPosition().x/48, (int)this->getPosition().y/48);
	return tilePos;
}

Entity::~Entity() {

}


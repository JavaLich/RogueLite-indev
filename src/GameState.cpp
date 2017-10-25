/*
 * GameState.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: A.Melachuri
 */

#include "GameState.h"

GameState::GameState() {
	status = MENU;
}

static void GameState::update() {
	if (status != PAUSED) {
		status = PAUSED;
	} else {
		status = PLAYING;
	}
}

GameState::~GameState() {
	// TODO Auto-generated destructor stub
}


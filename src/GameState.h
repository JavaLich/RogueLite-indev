/*
 * GameState.h
 *
 *  Created on: Oct 22, 2017
 *      Author: A.Melachuri
 */
#include <SFML/Graphics.hpp>

#ifndef SRC_GAMESTATE_H_
#define SRC_GAMESTATE_H_

class GameState {
public:
	GameState();
	virtual ~GameState();
	static const int MENU = 0;
	static const int PLAYING = 1;
	static const int PAUSED = 2;
	static int status;
	static void update();

private:


};

#endif /* SRC_GAMESTATE_H_ */

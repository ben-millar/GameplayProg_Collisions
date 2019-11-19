#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <typeinfo>

#include <Input.h>
#include <Player.h>
#include <PlayerFSM.h>
#include <Debug.h>

class State
{
public:
	virtual State* handleInput(Player& t_player, Input::Action t_in) = 0;

	virtual void enter(Player& t_player) = 0;
	virtual void exit(Player& t_player) = 0;

	virtual void update(Player& t_player) {}
};

#endif // ! ANIMATION_H
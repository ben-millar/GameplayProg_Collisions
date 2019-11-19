#ifndef CROUCHING_H
#define CROUCHING_H

#include "State.h"
class Crouching : public State
{
public:
	Crouching() {};
	~Crouching() {};
	State* handleInput(Player& t_player, Input::Action t_in);

	void enter(Player& t_player);
	void exit(Player& t_player);

	void update(Player& t_player);
	State* idle();
	State* walking();

private:
	vector<IntRect> m_frames{
		{0,200,200,200},
		{200,200,200,200},
		{400,200,200,200},
		{600,200,200,200}
	};
};

#endif //!CROUCHING_H
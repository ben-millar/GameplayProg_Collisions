#ifndef IDLE_H
#define IDLE_H

#include <State.h>

class Idle : public State
{
public:
	Idle() {};
	~Idle() {};
	State* handleInput(Player& t_player, Input::Action t_in);

	void enter(Player& t_player);
	void exit(Player& t_player);

	void update(Player& t_player);
	State* crouching();
	State* walking();
	State* jumping();
	State* climbing();

private:
	vector<IntRect> m_frames{
		{0,0,200,200},
		{200,0,200,200}
	};
};

#endif // !IDLE_H
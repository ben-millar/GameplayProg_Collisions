#ifndef CLIMBING_H
#define CLIMBING_H

#include <State.h>

class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};
	State* handleInput(Player& t_player, Input::Action t_in);

	void enter(Player& t_player);
	void exit(Player& t_player);

	void update(Player& t_player);

private:
	vector<IntRect> m_frames{
		{0,1000,200,200},
		{200,1000,200,200},
		{400,1000,200,200},
		{600,1000,200,200}
	};
};

#endif // !CLIMBING_H
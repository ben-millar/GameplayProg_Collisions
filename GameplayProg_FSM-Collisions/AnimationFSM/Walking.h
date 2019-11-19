#ifndef WALKING_H
#define WALKING_H
#include <State.h>

class Running : public State
{
public:
	Running() {};
	~Running() {};
	virtual State* handleInput(Player& t_player, Input::Action t_in);

	void enter(Player& t_player);
	void exit(Player& t_player);

	void update(Player& t_player);
	State* idle();
	State* sliding();
	State* jumping();

private:
	vector<IntRect> m_frames{
		{0,400,200,200},
		{200,400,200,200},
		{400,400,200,200},
		{600,400,200,200},
		{800,400,200,200},
		{1000,400,200,200}
	};
};

#endif //!WALKING_H
#ifndef JUMPING_H
#define JUMPING_H

#include <State.h>

class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};
	virtual State* handleInput(Player& t_player, Input::Action t_in);

	void enter(Player& t_player);
	void exit(Player& t_player);

	void update(Player& t_player);

private:

	sf::Clock m_jumpClock;
	sf::Time m_jumpTime{sf::seconds(1.75f)};

	bool m_goPrevious{ false };

	vector<IntRect> m_frames{
		{0,800,200,200},
		{200,800,200,200},
		{400,800,200,200},
		{600,800,200,200},
		{800,800,200,200},
		{1000,800,200,200},
		{1200,800,200,200},
		{1400,800,200,200}
	};
};

#endif // !JUMPING_H
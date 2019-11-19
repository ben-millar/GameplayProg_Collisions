#ifndef SLIDING_H
#define SLIDING_H

#include "State.h"
class Sliding : public State
{
public:
	Sliding() {};
	~Sliding() {};
	State* handleInput(Player& t_player, Input::Action t_in);

	void enter(Player& t_player);
	void exit(Player& t_player);

	void update(Player& t_player);

private:

	sf::Clock m_slideClock;
	sf::Time m_jumpTime{ sf::seconds(1.0f) };

	bool m_goPrevious{ false };

	vector<IntRect> m_frames{
		{0,600,200,200},
		{200,600,200,200},
		{400,600,200,200},
		{600,600,200,200},
		{800,600,200,200}
	};
};

#endif //!SLIDING_H
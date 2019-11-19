#include "Crouching.h"
#include "Idle.h"
#include "Walking.h"

State* Crouching::handleInput(Player& t_player, Input::Action t_in)
{
	switch (t_in)
	{
	case Input::Action::UP:
		return this->idle();
		break;
	case Input::Action::RIGHT:
		return this->walking();
		break;
	default:
		break;
	}
	return nullptr;
}

/////////////////////////////////////////////////////////////////////////

void Crouching::enter(Player& t_player)
{
	for (IntRect i : m_frames)
	{
		t_player.getAnimatedSprite().addFrame(i);
	}
}

/////////////////////////////////////////////////////////////////////////

void Crouching::exit(Player& t_player)
{
	t_player.getAnimatedSprite().clear();
}

/////////////////////////////////////////////////////////////////////////

void Crouching::update(Player& t_player)
{
}

/////////////////////////////////////////////////////////////////////////

State* Crouching::idle()
{
	std::cout << "Crouching -> Idle" << std::endl;
	return new Idle();
}

/////////////////////////////////////////////////////////////////////////

State* Crouching::walking()
{
	std::cout << "Crouching -> Running" << std::endl;
	return new Running();
}

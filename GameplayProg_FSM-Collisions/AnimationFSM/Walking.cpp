#include "Walking.h"
#include "Idle.h"
#include "Sliding.h"
#include "Jumping.h"

State* Running::handleInput(Player& t_player, Input::Action t_in)
{
	switch (t_in)
	{
	case Input::Action::JUMP:
		return this->jumping();
		break;
	case Input::Action::DOWN:
		return this->sliding();
		break;
	case Input::Action::LEFT:
		return this->idle();
		break;
	case Input::Action::RIGHT:
		return this->idle();
		break;
	default:
		break;
	}

	return nullptr;
}

/////////////////////////////////////////////////////////////////////////

void Running::enter(Player& t_player)
{
	for (IntRect i : m_frames)
	{
		t_player.getAnimatedSprite().addFrame(i);
	}
}

/////////////////////////////////////////////////////////////////////////

void Running::exit(Player& t_player)
{
	t_player.getAnimatedSprite().clear();
}

/////////////////////////////////////////////////////////////////////////

void Running::update(Player& t_player)
{
	if (t_player.getAnimatedSprite().getScale().x < 0.0f)
	{
		t_player.getAnimatedSprite().move({ -0.05f,0.0f });
	}
	else
	{
		t_player.getAnimatedSprite().move({ 0.05f,0.0f });
	}
}

/////////////////////////////////////////////////////////////////////////

State* Running::idle()
{
	std::cout << "Running -> Idle" << std::endl;
	return new Idle();
}

/////////////////////////////////////////////////////////////////////////

State* Running::sliding()
{
	std::cout << "Running -> Sliding" << std::endl;
	return new Sliding();
}

/////////////////////////////////////////////////////////////////////////

State* Running::jumping()
{
	std::cout << "Running -> Jumping" << std::endl;
	return new Jumping();
}
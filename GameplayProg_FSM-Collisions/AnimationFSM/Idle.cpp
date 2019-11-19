#include <Idle.h>
#include <Crouching.h>
#include <Walking.h>
#include <Jumping.h>
#include <Climbing.h>

#include <string>

State* Idle::handleInput(Player& t_player, Input::Action t_in)
{
	switch (t_in)
	{
	case Input::Action::JUMP:
		return this->jumping();
		break;
	case Input::Action::DOWN:
		return this->crouching();
		break;
	case Input::Action::RIGHT:
		t_player.getAnimatedSprite().setScale({ 1.0f,1.0f });
		return this->walking();
	case Input::Action::LEFT:
		t_player.getAnimatedSprite().setScale({ -1.0f,1.0f });
		return this->walking();
		break;
	case Input::Action::UP:
		return this->climbing();
		break;
	default:
		break;
	}

	return nullptr;
}

/////////////////////////////////////////////////////////////////////////

void Idle::enter(Player& t_player)
{
	for (IntRect i : m_frames)
	{
		t_player.getAnimatedSprite().addFrame(i);
	}
}

/////////////////////////////////////////////////////////////////////////

void Idle::exit(Player& t_player)
{
	t_player.getAnimatedSprite().clear();
}

/////////////////////////////////////////////////////////////////////////

void Idle::update(Player& t_player) {}

State* Idle::crouching()
{
	std::cout << "Idle -> Crouching" << std::endl;
	return new Crouching();
}

/////////////////////////////////////////////////////////////////////////

State* Idle::walking()
{
	std::cout << "Idle -> Running" << std::endl;
	return new Running();
}

/////////////////////////////////////////////////////////////////////////

State* Idle::jumping()
{
	std::cout << "Idle -> Jumping" << std::endl;
	return new Jumping();
}

/////////////////////////////////////////////////////////////////////////

State* Idle::climbing()
{
	std::cout << "Idle -> Climbing" << std::endl;
	return new Climbing();
}
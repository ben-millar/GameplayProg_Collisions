#include <Climbing.h>
#include <string>

State* Climbing::handleInput(Player& t_player, Input::Action t_in)
{
	switch (t_in)
	{
	case Input::Action::DOWN:
		std::cout << "Climbing -> Previous" << std::endl;
		return t_player.getPrevious();
		break;
	default:
		break;
	}
	return nullptr;
}

/////////////////////////////////////////////////////////////////////////

void Climbing::enter(Player& t_player)
{
	for (IntRect i : m_frames)
	{
		t_player.getAnimatedSprite().addFrame(i);
	}
}

/////////////////////////////////////////////////////////////////////////

void Climbing::exit(Player& t_player)
{
	t_player.getAnimatedSprite().clear();
}

/////////////////////////////////////////////////////////////////////////

void Climbing::update(Player& t_player)
{
}
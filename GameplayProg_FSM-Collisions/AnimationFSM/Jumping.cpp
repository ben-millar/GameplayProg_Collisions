#include <Jumping.h>

#include <string>

State* Jumping::handleInput(Player& t_player, Input::Action t_in)
{
	if (m_goPrevious)
	{
		std::cout << "Jumping -> Previous" << std::endl;
		return t_player.getPrevious();
	}
	else
	{
		return nullptr;
	}
}

/////////////////////////////////////////////////////////////////////////

void Jumping::enter(Player& t_player)
{
	for (IntRect i : m_frames)
	{
		t_player.getAnimatedSprite().addFrame(i);
	}

	m_jumpClock.restart();
}

/////////////////////////////////////////////////////////////////////////

void Jumping::exit(Player& t_player)
{
	t_player.getAnimatedSprite().clear();

	m_goPrevious = false;
}

/////////////////////////////////////////////////////////////////////////

void Jumping::update(Player& t_player)
{
	if (m_jumpClock.getElapsedTime() > m_jumpTime)
	{
		m_goPrevious = true;
	}

	if (t_player.getAnimatedSprite().getScale().x < 0.0f)
	{
		t_player.getAnimatedSprite().move({ -0.05f,0.0f });
	}
	else
	{
		t_player.getAnimatedSprite().move({ 0.05f,0.0f });
	}
}
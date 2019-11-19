#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Jumping.h>
#include <Debug.h>

#include <SFML/Graphics.hpp>

Player::Player()
{
	m_FSM.setCurrent(new Idle());
	m_FSM.setPrevious(new Idle());

	m_currentInput = Input::Action::DEFAULT;

	updateBoundingBox();
}

/////////////////////////////////////////////////////////////////////////

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_FSM.setCurrent(new Idle());
	m_FSM.setPrevious(new Idle());

	m_currentInput = Input::Action::DEFAULT;
}

/////////////////////////////////////////////////////////////////////////

Player::~Player() 
{

}

/////////////////////////////////////////////////////////////////////////

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

/////////////////////////////////////////////////////////////////////////

void Player::setInput(Input t_in)
{
	m_currentInput = t_in.getCurrent();

	handleInput();
}

/////////////////////////////////////////////////////////////////////////

void Player::handleInput()
{
	DEBUG_MSG("Handle Input");

	State* m_newState = m_FSM.getCurrent()->handleInput(*this, m_currentInput);

	// if we recieved back a state ptr
	if (m_newState != nullptr)
	{
		m_FSM.getCurrent()->exit(*this);

		// This could be improved with an object pool pattern

		m_FSM.setPrevious(m_FSM.getCurrent());

		m_FSM.setCurrent(m_newState);

		m_FSM.getCurrent()->enter(*this);

		m_currentInput = Input::Action::DEFAULT;
	}
}

/////////////////////////////////////////////////////////////////////////

State* Player::getPrevious()
{
	return m_FSM.getPrevious();
}

/////////////////////////////////////////////////////////////////////////

void Player::update()
{
	m_FSM.getCurrent()->update(*this);
	m_animated_sprite.update();

	updateBoundingBox();
}

/////////////////////////////////////////////////////////////////////////

void Player::updateBoundingBox()
{
	sf::IntRect size = m_animated_sprite.getTextureRect();
	m_boundingBox.min.x = m_animated_sprite.getPosition().x - size.width / 4.0f;
	m_boundingBox.min.y = m_animated_sprite.getPosition().y - size.height / 4.0f;

	m_boundingBox.max.x = m_animated_sprite.getPosition().x + size.width / 4.0f;
	m_boundingBox.max.y = m_animated_sprite.getPosition().y + size.height / 4.0f;
}

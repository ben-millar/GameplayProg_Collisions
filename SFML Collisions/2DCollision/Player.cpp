#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player() : GameObject()
{
	m_player_fsm.setCurrent(new Idle());
	m_player_fsm.setPrevious(new Idle());

	init();
}

Player::Player(const AnimatedSprite& s) : GameObject(s)
{
	m_player_fsm.setCurrent(new Idle());
	m_player_fsm.setPrevious(new Idle());

	init();
}

Player::~Player()
{
}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	case Input::Action::IDLE:
		//std::cout << "Player Idling" << std::endl;
		m_player_fsm.idle();
		break;
	case Input::Action::UP:
		//std::cout << "Player Up" << std::endl;
		m_player_fsm.climbing();
		break;
	case Input::Action::LEFT:
		//std::cout << "Player Left" << std::endl;
		m_player_fsm.jumping();
		break;
	case Input::Action::RIGHT:
		//std::cout << "Player Idling" << std::endl;
		m_player_fsm.jumping();
		break;
	default:
		break;
	}
}

void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite.update();

	m_boundingBox.setPosition(m_animated_sprite.getPosition());

	m_boundingBox.setFillColor(sf::Color(0,0,0,0));
	m_boundingBox.setOutlineColor(sf::Color::White);
}

void Player::colliding(GameObject& t_collidingWith)
{
	t_collidingWith.colliding(*this); // Sorry, I hit you!

	m_boundingBox.setFillColor(sf::Color(255,0,0,128));
	m_boundingBox.setOutlineColor(sf::Color::Red);
}

void Player::draw(sf::RenderWindow& t_window)
{
	t_window.draw(getAnimatedSprite());
	t_window.draw(m_boundingBox);
}

void Player::init()
{
	float h = m_animated_sprite.getGlobalBounds().height;
	float w = m_animated_sprite.getGlobalBounds().width / 6.0f;

	m_boundingBox.setSize(sf::Vector2f(w, h));

	m_boundingBox.setPosition(m_animated_sprite.getPosition());

	m_boundingBox.setOutlineThickness(2.0f);

	m_boundingBox.setFillColor(sf::Color(0,0,0,0));
	m_boundingBox.setOutlineColor(sf::Color::White);
}

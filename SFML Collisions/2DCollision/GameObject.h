#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <Input.h>
#include <PlayerFSM.h>
#include <AnimatedSprite.h>
#include <SFML/Graphics.hpp>

class GameObject
{
protected:
	PlayerFSM m_player_fsm;
	AnimatedSprite m_animated_sprite;
	sf::RectangleShape m_boundingBox;
	GameObject();
	GameObject(const AnimatedSprite&);

	virtual void init() = 0;

public:
	virtual ~GameObject() = 0;
	virtual AnimatedSprite& getAnimatedSprite() = 0;
	virtual void handleInput(Input) = 0;
	virtual void update() = 0;
	virtual void colliding(GameObject& t_collidingWith) = 0;
	virtual void draw(sf::RenderWindow& t_window) = 0;
};

#endif // !GAME_OBJECT_H

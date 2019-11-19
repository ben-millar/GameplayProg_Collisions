#ifndef PLAYER_H
#define PLAYER_H

#include <Input.h>
#include <PlayerFSM.h>
#include <AnimatedSprite.h>
#include <tinyc2.h>

class Player
{
private:
	Input::Action m_currentInput;

	PlayerFSM m_FSM;
	AnimatedSprite m_animated_sprite;
	Player();

public:
	Player(const AnimatedSprite&);
	~Player();
	AnimatedSprite& getAnimatedSprite();

	void setInput(Input t_in);

	void handleInput();
	State* getPrevious();
	void update();
	void updateBoundingBox();

	c2AABB m_boundingBox;
};

#endif // !PLAYER_H
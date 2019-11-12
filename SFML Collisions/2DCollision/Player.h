#ifndef PLAYER_H
#define PLAYER_H

#include <GameObject.h>
#include <Input.h>
#include <PlayerFSM.h>
#include <AnimatedSprite.h>

class Player : public GameObject
{

public:
	Player();
	~Player();
	Player(const AnimatedSprite&);
	AnimatedSprite& getAnimatedSprite();
	void handleInput(Input) override;
	void update();
	void colliding(GameObject& t_collidingWith) override;
	void draw(sf::RenderWindow& t_window) override;

private:
	void init() override;
};

#endif // !PLAYER_H

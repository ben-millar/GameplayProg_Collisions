#ifndef NPC_H
#define NPC_H

#include <GameObject.h>
#include <Input.h>
#include <PlayerFSM.h>
#include <AnimatedSprite.h>

class NPC : public GameObject
{

public:
	NPC();
	~NPC();
	NPC(const AnimatedSprite&);
	AnimatedSprite& getAnimatedSprite() override;
	void handleInput(Input) override;
	void update() override;
	void colliding(GameObject& t_collidingWith) override;
	void draw(sf::RenderWindow& t_window) override;

private:
	void init() override;
};

#endif // !NPC_H

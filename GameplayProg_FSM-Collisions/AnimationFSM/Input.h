#ifndef INPUT_H
#define INPUT_H
class Input
{
public:
	Input();
	~Input();

	enum class Action
	{
		DEFAULT,
		IDLE,
		JUMP,
		DOWN, // crouch OR slide, contenxtual
		LEFT,
		RIGHT,
		UP // climb OR stand, contextual
	};

	void setCurrent(Action);
	Action getCurrent();

private:
	Action m_current;
};
#endif
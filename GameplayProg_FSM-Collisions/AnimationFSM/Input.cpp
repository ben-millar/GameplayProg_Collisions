#include <Input.h>

Input::Input() 
{
	m_current = Action::IDLE;
}
Input::~Input() {}

void Input::setCurrent(Action a) {
	m_current = a;
}

Input::Action Input::getCurrent() {
	return m_current;
}
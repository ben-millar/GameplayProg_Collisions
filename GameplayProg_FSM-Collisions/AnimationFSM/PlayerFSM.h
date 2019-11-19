#ifndef PLAYER_FSM_H
#define PLAYER_FSM_H

/// <summary>
/// This acts as a wrapper for our state class, providing an interface for all interactions and tracking previous states
/// </summary>
class PlayerFSM
{

	// Please review very good article on Stackoverflow
	// which covers some solutions to circular dependacies
	// https://stackoverflow.com/questions/625799/resolve-build-errors-due-to-circular-dependency-amongst-classes

private:
	// why are we using the keyword 'class' here?
	class State* m_current; // note order of m_current is 
							// prior to setCurrent
	class State* m_previous;
public:
	PlayerFSM();
	~PlayerFSM();
	void setCurrent(State* s);
	void setPrevious(State* s);
	State* getCurrent();
	State* getPrevious();
};

#endif // !PLAYER_FSM_H

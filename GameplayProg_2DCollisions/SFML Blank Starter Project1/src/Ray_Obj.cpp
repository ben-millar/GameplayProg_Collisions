#include "Ray_Obj.h"

void Ray_Obj::init()
{
	m_lineStart.position = { 0.0f,0.0f };
	m_lineStart.color = sf::Color::White;

	m_lineEnd.position = { 0.0f,0.0f };
	m_lineEnd.color = sf::Color::White;

	setupShape();
	updateBoundingBox();
}

/////////////////////////////////////////////////////////////

void Ray_Obj::setupShape()
{
	m_shape.append(m_lineStart);
	m_shape.append(m_lineEnd);
}

/////////////////////////////////////////////////////////////

void Ray_Obj::update(sf::Time t_deltaTime)
{
	updateBoundingBox();
}

/////////////////////////////////////////////////////////////

void Ray_Obj::updateBoundingBox()
{
	// Get a unit vector for our line
	sf::Vector2f deltaPos = m_lineEnd.position - m_lineStart.position;
	float magnitude = sqrt((deltaPos.x * deltaPos.x) + (deltaPos.y * deltaPos.y));

	sf::Vector2f unit = deltaPos / magnitude;

	m_boundingBox.d = { unit.x, unit.y };

	m_boundingBox.p = { m_lineStart.position.x, m_lineStart.position.y };

	m_boundingBox.t = magnitude;
}

/////////////////////////////////////////////////////////////

void Ray_Obj::draw(sf::RenderWindow& t_window)
{
	m_lineEnd.position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(t_window));
	m_shape[1] = m_lineEnd;

	t_window.draw(m_shape);
}
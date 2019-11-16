#include "Polygon_Obj.h"

void Polygon_Obj::init()
{
	float xPos = static_cast<float>(rand() % 700 + 51); // range 50–750
	float yPos = static_cast<float>(rand() % 500 + 51); // range 50–550

	float xVel = ((rand() % 50 + 10) / 10.0f); // range 1.0f–5.0f
	float yVel = ((rand() % 50 + 10) / 10.0f); // range 1.0f–5.0f

	m_position = { xPos, yPos };
	m_velocity = { xVel, yVel };

	setupShape();
	updateBoundingBox();
}

/////////////////////////////////////////////////////////////

void Polygon_Obj::setupShape()
{
	m_shape.setPointCount(3);

	m_shape.setPoint(0, { m_a.x, m_a.y });
	m_shape.setPoint(1, { m_b.x, m_b.y });
	m_shape.setPoint(2, { m_c.x, m_c.y });

	m_shape.setOrigin({ 0.0f,0.0f });

	m_shape.setFillColor(sf::Color::Red);
}

/////////////////////////////////////////////////////////////

void Polygon_Obj::update(sf::Time t_deltaTime)
{
	m_position += m_velocity;

	if ((m_position.x + m_a.x) < 0.0f || (m_position.x + m_c.x) > 800.0f)
	{
		m_velocity.x *= -1.0f;
	}

	if ((m_position.y + m_b.y) < 0.0f || (m_position.y + m_a.y) > 600.0f)
	{
		m_velocity.y *= -1.0f;
	}

	updateBoundingBox();
}

/////////////////////////////////////////////////////////////

void Polygon_Obj::updateBoundingBox()
{
	m_boundingBox.count = 3;

	m_boundingBox.verts[0] = { m_position.x + m_a.x, m_position.y + m_a.y };
	m_boundingBox.verts[1] = { m_position.x + m_b.x, m_position.y + m_b.y };
	m_boundingBox.verts[2] = { m_position.x + m_c.x, m_position.y + m_c.y };

	c2MakePoly(&m_boundingBox);
}

/////////////////////////////////////////////////////////////

void Polygon_Obj::draw(sf::RenderWindow& t_window)
{
	m_shape.setPosition(m_position);
	t_window.draw(m_shape);
}
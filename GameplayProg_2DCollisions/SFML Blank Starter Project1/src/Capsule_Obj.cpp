#include "Capsule_Obj.h"

void Capsule_Obj::init()
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

void Capsule_Obj::isColliding()
{
	m_shape.setOutlineColor(sf::Color::Yellow);
}

/////////////////////////////////////////////////////////////

void Capsule_Obj::setupShape()
{
	m_shape.init();
	m_shape.setColor(sf::Color::Red);
	m_shape.setPosition(m_position);

	m_shape.a.setOutlineThickness(2.0f);
	m_shape.b.setOutlineThickness(2.0f);
	m_shape.rect.setOutlineThickness(2.0f);
}

/////////////////////////////////////////////////////////////

void Capsule_Obj::update(sf::Time t_deltaTime)
{
	m_position += m_velocity;

	if ((m_position.x - m_shape.radius) < 0.0f || (m_position.x + m_shape.radius) > 800.0f)
	{
		m_velocity.x *= -1.0f;
		m_position.x += m_velocity.x;
	}

	if ((m_position.y - (m_shape.length / 2.0f + m_shape.radius)) < 0.0f ||
		 m_position.y + (m_shape.length / 2.0f + m_shape.radius) > 600.0f)
	{
		m_velocity.y *= -1.0f;
		m_position.y += m_velocity.y;
	}

	updateBoundingBox();

	m_shape.setOutlineColor(sf::Color(0U, 0U, 0U, 0U));
}

/////////////////////////////////////////////////////////////

void Capsule_Obj::updateBoundingBox()
{
	m_boundingBox.a.x = m_shape.a.getPosition().x;
	m_boundingBox.a.y = m_shape.a.getPosition().y;

	m_boundingBox.b.x = m_shape.b.getPosition().x;
	m_boundingBox.b.y = m_shape.b.getPosition().y;

	m_boundingBox.r = m_shape.radius;
}

/////////////////////////////////////////////////////////////

void Capsule_Obj::draw(sf::RenderWindow& t_window)
{
	m_shape.setPosition(m_position);
	m_shape.draw(t_window);
}

///////////////////////////////////////////////////////////// 

void Capsule_Obj::capsuleShape::init()
{
	a.setRadius(radius);
	b.setRadius(radius);
	rect.setSize({ radius * 2.0f, length });

	a.setOrigin({ radius, radius });
	b.setOrigin({ radius, radius });
	rect.setOrigin({ radius, length / 2.0f });
}

/////////////////////////////////////////////////////////////

void Capsule_Obj::capsuleShape::setPosition(sf::Vector2f t_pos)
{
	rect.setPosition(t_pos);
	a.setPosition({ t_pos.x, (t_pos.y - length / 2.0f) });
	b.setPosition({ t_pos.x, (t_pos.y + length / 2.0f) });
}

/////////////////////////////////////////////////////////////

void Capsule_Obj::capsuleShape::setColor(sf::Color t_color)
{
	a.setFillColor(t_color);
	b.setFillColor(t_color);
	rect.setFillColor(t_color);
}

/////////////////////////////////////////////////////////////

void Capsule_Obj::capsuleShape::setOutlineColor(sf::Color t_color)
{
	a.setOutlineColor(t_color);
	b.setOutlineColor(t_color);
	rect.setOutlineColor(t_color);
}

/////////////////////////////////////////////////////////////

void Capsule_Obj::capsuleShape::draw(sf::RenderWindow& t_window)
{
	t_window.draw(a);
	t_window.draw(b);
	t_window.draw(rect);
}

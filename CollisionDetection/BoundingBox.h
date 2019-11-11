#pragma once

class BoundingBox
{
public:
	class Point
	{
	public:
		Point() = default;
		Point(float t_x, float t_y) : m_x{ t_x }, m_y{ t_y } {};

		float x() { return m_x; }
		float y() { return m_y; }

	private:
		float m_x{ 0.0f }, m_y{ 0.0f };
	};

	class Circle 
	{
	public:
		Circle() = default;
		Circle(BoundingBox::Point t_point, float t_rad) : m_p{ t_point }, m_radius{ t_rad } {};
		Circle(float t_x, float t_y, float t_rad) : m_p(t_x, t_y), m_radius{ t_rad } {};

		BoundingBox::Point point() { return m_p; }
		float radius() { return m_radius; }

	private:
		Point m_p;
		float m_radius{ 0.0f };
	};

	class AABB 
	{
	public:
		AABB() = default;
		AABB(BoundingBox::Point t_point, float t_width, float t_height) : m_p{ t_point }, m_width{ t_width }, m_height{ t_height } {};
		AABB(float t_x, float t_y, float t_width, float t_height) : m_p(t_x, t_y), m_width{ t_width }, m_height{ t_height } {};

		BoundingBox::Point point() { return m_p; }
		float width() { return m_width; }
		float height() { return m_height; }

	private:
		Point m_p;
		float m_width{ 0.0f }, m_height{ 0.0f };
	};
};
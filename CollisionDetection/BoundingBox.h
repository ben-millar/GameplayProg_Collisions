#pragma once

class BoundingBox
{
public:
	class Point
	{
	public:
		Point() = default;
		Point(float t_x, float t_y) : x{ t_x }, y{ t_y } {};
		float x{ 0.0f }, y{ 0.0f };
	};

	class Circle 
	{
	public:
		Circle() = default;
		Circle(BoundingBox::Point t_point, float t_rad) : p{ t_point }, radius{ t_rad } {};
		Circle(float t_x, float t_y, float t_rad) : p(t_x, t_y), radius{ t_rad } {};
		Point p;
		float radius{ 0.0f };
	};

	class AABB 
	{
	public:
		AABB() = default;
		AABB(BoundingBox::Point t_point, float t_width, float t_height) : p{ t_point }, w{ t_width }, h{ t_height } {};
		AABB(float t_x, float t_y, float t_width, float t_height) : p(t_x, t_y), w{ t_width }, h{ t_height } {};
		Point p;
		float w{ 0.0f }, h{ 0.0f };
	};
};
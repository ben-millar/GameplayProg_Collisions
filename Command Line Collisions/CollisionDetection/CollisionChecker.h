#pragma once

#include "BoundingBox.h"

class CollisionChecker
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="t_p1"></param>
	/// <param name="t_p2"></param>
	/// <returns></returns>
	static bool colliding(BoundingBox::Point& t_p1, BoundingBox::Point& t_p2);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="t_c1"></param>
	/// <param name="t_c2"></param>
	/// <returns></returns>
	static bool colliding(BoundingBox::Circle& t_c1, BoundingBox::Circle& t_c2);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="t_box1"></param>
	/// <param name="t_box2"></param>
	/// <returns></returns>
	static bool colliding(BoundingBox::AABB& t_box1, BoundingBox::AABB& t_box2);

private:
};
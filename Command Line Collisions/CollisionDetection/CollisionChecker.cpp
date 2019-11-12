#include "CollisionChecker.h"

bool CollisionChecker::colliding(BoundingBox::Point& t_p1, BoundingBox::Point& t_p2)
{
	return false;
}

bool CollisionChecker::colliding(BoundingBox::Circle& t_c1, BoundingBox::Circle& t_c2)
{
	return false;
}

bool CollisionChecker::colliding(BoundingBox::AABB& t_box1, BoundingBox::AABB& t_box2)
{
	return false;
}

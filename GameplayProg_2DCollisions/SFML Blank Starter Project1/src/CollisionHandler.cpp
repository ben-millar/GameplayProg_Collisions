#define TINYC2_IMPL

#include "CollisionHandler.h"

bool CollisionHandler::resolve(AABB_Obj const& t_aabb, Capsule_Obj const& t_capsule)
{
	return c2AABBtoCapsule(*t_aabb.getBounds(), *t_capsule.getBounds());
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::resolve(AABB_Obj const& t_aabb, Circle_Obj const& t_circle)
{
	return c2CircletoAABB(*t_circle.getBounds(), *t_aabb.getBounds());
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::resolve(AABB_Obj const& t_aabb, Polygon_Obj const& t_poly)
{
	return c2AABBtoPoly(*t_aabb.getBounds(), t_poly.getBounds(), nullptr);
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::resolve(AABB_Obj const& t_aabb, Ray_Obj& t_ray)
{
	return c2RaytoAABB(*t_ray.getBounds(), *t_aabb.getBounds(), t_ray.getRaycast());
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::resolve(Capsule_Obj const& t_capsule, Circle_Obj const& t_circle)
{
	return c2CircletoCapsule(*t_circle.getBounds(), *t_capsule.getBounds());
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::resolve(Capsule_Obj const& t_capsule, Polygon_Obj const& t_poly)
{
	return c2CapsuletoPoly(*t_capsule.getBounds(), t_poly.getBounds(), nullptr);
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::resolve(Capsule_Obj const& t_capsule, Ray_Obj& t_ray)
{
	return c2RaytoCapsule(*t_ray.getBounds(), *t_capsule.getBounds(), t_ray.getRaycast());
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::resolve(Circle_Obj const& t_circle, Polygon_Obj const& t_poly)
{
	return c2CircletoPoly(*t_circle.getBounds(), t_poly.getBounds(), nullptr);
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::resolve(Circle_Obj const& t_circle, Ray_Obj& t_ray)
{
	return c2RaytoCircle(*t_ray.getBounds(), *t_circle.getBounds(), t_ray.getRaycast());
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::resolve(Polygon_Obj const& t_poly, Ray_Obj& t_ray)
{
	return c2RaytoPoly(*t_ray.getBounds(), t_poly.getBounds(), nullptr, t_ray.getRaycast());
}
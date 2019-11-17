#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <AABB_Obj.h>
#include <Capsule_Obj.h>
#include <Circle_Obj.h>
#include <Polygon_Obj.h>
#include <Ray_Obj.h>
#include<tinyc2.h>

class CollisionHandler
{
public:
	static bool resolve(AABB_Obj const&, Capsule_Obj const&);
	static bool resolve(AABB_Obj const&, Circle_Obj const&);
	static bool resolve(AABB_Obj const&, Polygon_Obj const&);
	static bool resolve(AABB_Obj const&, Ray_Obj&);
	static bool resolve(Capsule_Obj const&, Circle_Obj const&);
	static bool resolve(Capsule_Obj const&, Polygon_Obj const&);
	static bool resolve(Capsule_Obj const&, Ray_Obj&);
	static bool resolve(Circle_Obj const&, Polygon_Obj const&);
	static bool resolve(Circle_Obj const&, Ray_Obj&);
	static bool resolve(Polygon_Obj const&, Ray_Obj&);
};

#endif //!COLLISIONHANDLER_H
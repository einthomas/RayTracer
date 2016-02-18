#ifndef PLANE_H
#define PLANE_H

#include "mymath.h"
#include "vec3.h"
#include "worldobject.h"
#include "ray.h"

class Plane : public WorldObject
{
public:
    Plane();
	Plane(vec3 pos, vec3 normal, vec3 color);
	bool intersects(Ray ray, double& t);

private:
	vec3 normal;
};

#endif // PLANE_H

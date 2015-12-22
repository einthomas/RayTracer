#ifndef SPHERE_H
#define SPHERE_H

#include "worldobject.h"
#include "mymath.h"
#include "ray.h"

class Sphere : public WorldObject
{
public:
    double radius, radius2;

    Sphere(vec3 pos, vec3 color, double radius);
    bool intersects(Ray& ray, double& t);
};

#endif // SPHERE_H

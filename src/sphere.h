#ifndef SPHERE_H
#define SPHERE_H

#include "mymath.h"
#include "vec3.h"
#include "worldobject.h"
#include "ray.h"

class Sphere : public WorldObject
{
public:
    double radius, radius2;

    Sphere();
    Sphere(vec3 pos, vec3 color, double radius);
    bool intersects(Ray ray, double& t);
};

#endif // SPHERE_H

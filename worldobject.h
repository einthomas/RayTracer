#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include "vec3.h"
#include "ray.h"

class Ray;

class WorldObject {
public:
    vec3 pos;
    vec3 color;

    virtual bool intersects(Ray ray, double& t) = 0;
};

#endif // WORLDOBJECT_H

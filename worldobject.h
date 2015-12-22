#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include "vec3.h"
#include "ray.h"

class WorldObject {
public:
    vec3 pos;
    vec3 color;

    virtual bool intersects(const Ray& ray, double& t) = 0;
};

#endif // WORLDOBJECT_H

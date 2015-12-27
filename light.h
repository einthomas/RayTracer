#ifndef LIGHT_H
#define LIGHT_H

#include "vec3.h"
#include "worldobject.h"
#include "sphere.h"

class Light : public WorldObject {
public:
    vec3 dir;
    WorldObject *shape;

    Light(vec3 pos, vec3 dir, vec3 color);
    Light(vec3 pos, vec3 dir, vec3 color, double radius);
    bool intersects(Ray ray, double& t);
    virtual vec3 applyShading(vec3 fragColor, vec3 fragPos, vec3 normal) = 0;
};

#endif // LIGHT_H

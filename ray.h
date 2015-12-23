#ifndef RAY_H
#define RAY_H

#include <vector>
#include <memory>
#include <cstdlib>
#include <iterator>
#include <float.h>

#include "vec3.h"
#include "worldobject.h"

class WorldObject;

class Ray {
public:
    vec3 pos;
    vec3 dir;

    Ray();
    Ray(vec3 pos, vec3 dir);
    vec3 cast(std::vector<std::unique_ptr<WorldObject>> &objects);
    bool trace(const WorldObject *&hitObject, double &t, std::vector<std::unique_ptr<WorldObject>> &objects);
};

#endif // RAY_H

#ifndef RAY_H
#define RAY_H

#include <vector>
#include <memory>
#include <cstdlib>
#include <iterator>
#include <float.h>

#include "vec3.h"
#include "light.h"

class WorldObject;
class Light;

class Ray {
public:
    vec3 pos;
    vec3 dir;

    Ray();
    Ray(vec3 pos, vec3 dir);
    vec3 cast(std::vector<std::unique_ptr<WorldObject>> &objects, std::vector<std::unique_ptr<Light>> &lights);
    bool trace(const WorldObject *&hitObject, double &t, std::vector<std::unique_ptr<WorldObject>> &objects);

private:
    vec3 applyShading(std::vector<std::unique_ptr<Light>> &lights, vec3 color, vec3 normal, vec3 viewDir);
};

#endif // RAY_H

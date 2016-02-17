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
	vec3 cast(std::vector<std::unique_ptr<WorldObject>> &objects, std::vector<std::unique_ptr<Light>> &lights, int times);
	bool trace(WorldObject *&hitObject, double &t, std::vector<std::unique_ptr<WorldObject>> &objects, WorldObject *ignore);

private:
	vec3 cast(std::vector<std::unique_ptr<WorldObject>> &objects, std::vector<std::unique_ptr<Light>> &lights, int times, WorldObject *ignore);
};

#endif // RAY_H



/*
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
    vec3 cast(std::vector<std::unique_ptr<WorldObject>> &objects, std::vector<std::unique_ptr<Light>> &lights, int times);
    bool trace(const WorldObject *&hitObject, double &t, std::vector<std::unique_ptr<WorldObject>> &objects);

private:
};

#endif // RAY_H
*/

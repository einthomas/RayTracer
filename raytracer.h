#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <vector>
#include <fstream>
#include <ctime>

#include "vec2.h"
#include "vec3.h"
#include "mymath.h"
#include "ray.h"
#include "worldobject.h"

using namespace std;

class RayTracer
{
public:
    RayTracer(vec2 imageSize);

    void render(std::vector<WorldObject> objects);

private:
    vec2 imageSize;

    void saveToFile(std::string filename, std::vector<vec3> frameBuffer);
    void writeLogFile(double duration);
};

#endif // RAYTRACER_H

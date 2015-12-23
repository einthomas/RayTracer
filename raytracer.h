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

    void render(std::vector<std::unique_ptr<WorldObject>> &objects, double fov);

private:
    vec2 imageSize;
    double imageAspectRatio;

    void saveToFile(std::string filename, std::vector<vec3> frameBuffer);
    void writeLogFile(double duration);
};

#endif // RAYTRACER_H

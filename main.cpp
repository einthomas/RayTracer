#include <iostream>
#include <memory>
#include <vector>

#include "worldobject.h"
#include "sphere.h"
#include "light.h"
#include "globallight.h"
#include "raytracer.h"
#include "vec3.h"

int main() {
    std::vector<std::unique_ptr<WorldObject>> objects;
    objects.push_back(std::unique_ptr<WorldObject>(new Sphere(vec3(0.0, 0.0, -8.0), vec3(1.0, 0.8, 0.4), 0.8)));
    objects.push_back(std::unique_ptr<WorldObject>(new Sphere(vec3(4.0, 0.0, -8.0), vec3(1.0, 0.1, 0.2), 0.6)));
    objects.push_back(std::unique_ptr<WorldObject>(new Sphere(vec3(-4.0, 0.0, -8.0), vec3(0.2, 0.7, 0.9), 0.6)));

    std::vector<std::unique_ptr<Light>> lights;
    lights.push_back(std::unique_ptr<Light>(new GlobalLight(vec3(-6.0, 6.0, 0.0), vec3(1.0, 1.0, 1.0))));

    RayTracer rayTracer(vec2(1920, 1080));
    rayTracer.render(objects, lights, 50);

    return 0;
}

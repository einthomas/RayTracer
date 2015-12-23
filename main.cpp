#include <iostream>
#include <memory>
#include <vector>

#include "worldobject.h"
#include "raytracer.h"
#include "sphere.h"
#include "vec3.h"

int main() {
    std::vector<std::unique_ptr<WorldObject>> objects;
    objects.push_back(std::unique_ptr<WorldObject>(new Sphere(vec3(0.0, 0.0, -1.0), vec3(1.0, 0.8, 0.4), 0.5)));

    RayTracer rayTracer(vec2(1920, 1080));
    rayTracer.render(objects, 50);

    return 0;
}

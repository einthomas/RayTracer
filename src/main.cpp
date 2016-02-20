#include <iostream>
#include <memory>
#include <vector>

#include "worldobject.h"
#include "sphere.h"
#include "plane.h"
#include "light.h"
#include "globallight.h"
#include "raytracer.h"
#include "vec3.h"
#include "orthographic.h"
#include "pinhole.h"

int main() {
    std::vector<std::unique_ptr<WorldObject>> objects;
    objects.push_back(std::unique_ptr<WorldObject>(new Sphere(vec3(0.0, 0.0, -8.0), vec3(1.0, 0.8, 0.4), 0.8)));
	objects.push_back(std::unique_ptr<WorldObject>(new Sphere(vec3(0.0, -1.7, -8.0), vec3(1.0, 0.8, 0.4), 0.8)));
	objects.push_back(std::unique_ptr<WorldObject>(new Sphere(vec3(0.0, 1.9, -8.0), vec3(1.0, 0.8, 0.4), 0.8)));
    objects.push_back(std::unique_ptr<WorldObject>(new Sphere(vec3(1.5, 0.0, -9.0), vec3(1.0, 0.1, 0.2), 0.6)));
    objects.push_back(std::unique_ptr<WorldObject>(new Sphere(vec3(-4.0, 0.0, -12.0), vec3(0.2, 0.7, 0.9), 0.6)));
	objects.push_back(std::unique_ptr<WorldObject>(new Sphere(vec3(-4.0, -1.6f, -12.0), vec3(0.2, 0.7, 0.9), 0.6)));
	//objects.push_back(std::unique_ptr<WorldObject>(new Plane(vec3(0.42372f, -0.70379f, -12.886f), vec3(0.0f, 0.0f, -12.886f), vec3(1.0f, 1.0f, 1.0f))));
	objects.push_back(std::unique_ptr<WorldObject>(new Plane(vec3(0.03359f, -5.3307f, -12.886f), vec3(0.0f, 1.0f, 0.0f), vec3(1.0f))));

    std::vector<std::unique_ptr<Light>> lights;
	lights.push_back(std::unique_ptr<Light>(new GlobalLight(vec3(-0.03292f, 4.4421f, -6.4661f), vec3(1.0, 1.0, 1.0))));
    //lights.push_back(std::unique_ptr<Light>(new GlobalLight(vec3(-6.0, 6.0, 0.0), vec3(1.0, 1.0, 1.0))));

    RayTracer rayTracer(vec2(800, 400));
    rayTracer.render(objects, lights, new Orthographic(vec3(), 20));
	//rayTracer.render(objects, lights, new Pinhole(vec3(), 20));

    return 0;
}

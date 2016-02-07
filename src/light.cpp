#include "light.h"

Light::Light(vec3 pos, vec3 dir, vec3 color) {
    this->pos = pos;
    this->dir = dir;
    this->color = color;

    visible = false;
}

Light::Light(vec3 pos, vec3 dir, vec3 color, double radius) {
    this->dir = dir;

    shape = new Sphere(pos, color, radius);
}

bool Light::intersects(Ray ray, double& t) {
    if (shape != nullptr) {
        return shape->intersects(ray, t);
    }

    return false;
}

#include "ray.h"

Ray::Ray() { }

Ray::Ray(vec3 pos, vec3 dir) {
    this->pos = pos;
    this->dir = dir;
}

vec3 Ray::cast(std::vector<std::unique_ptr<WorldObject>> &objects) {
    const WorldObject *hitObject = nullptr;
    vec3 color;
    double t;

    if (trace(hitObject, t, objects)) {
        if (hitObject != nullptr) {
            vec3 hitPoint = dir * t + pos;
            vec3 normal = (hitPoint - hitObject->pos).normalize();

            // TODO: Improve shading
            color = hitObject->color;
        }
    }

    return color;
}

bool Ray::trace(const WorldObject *&hitObject, double &t, std::vector<std::unique_ptr<WorldObject>> &objects) {
    t = DBL_MAX;
    std::vector<std::unique_ptr<WorldObject>>::iterator iter = objects.begin();

    for (; iter != objects.end(); iter++) {
        double tTmp = DBL_MAX;
        if ((*iter)->intersects(*this, tTmp) && tTmp < t) {
            hitObject = iter->get();
        }
    }

    if (hitObject != nullptr) {
        return true;
    }

    return false;
}

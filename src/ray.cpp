#include "ray.h"

Ray::Ray() { }

Ray::Ray(vec3 pos, vec3 dir) {
    this->pos = pos;
    this->dir = dir;
}

vec3 Ray::cast(std::vector<std::unique_ptr<WorldObject>> &objects, std::vector<std::unique_ptr<Light>> &lights) {
    const WorldObject *hitObject = nullptr;
    vec3 color;
    double t;

    if (trace(hitObject, t, objects)) {
        if (hitObject != nullptr) {
            vec3 hitPoint = dir * t + pos;
            vec3 normal = (hitPoint - hitObject->pos).normalize();

            std::vector<std::unique_ptr<Light>>::iterator iter = lights.begin();
            for (; iter != lights.end(); iter++) {
                color += (*iter)->applyShading(hitObject->color, hitPoint, normal);
            }
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
            t = tTmp;
            hitObject = iter->get();
        }
    }

    if (hitObject != nullptr) {
        return true;
    }

    return false;
}

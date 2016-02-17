#include "ray.h"

Ray::Ray() { }

Ray::Ray(vec3 pos, vec3 dir) {
	this->pos = pos;
	this->dir = dir;
}

vec3 Ray::cast(std::vector<std::unique_ptr<WorldObject>> &objects, std::vector<std::unique_ptr<Light>> &lights, int times) {
	return cast(objects, lights, times, nullptr);
}

vec3 Ray::cast(std::vector<std::unique_ptr<WorldObject>> &objects, std::vector<std::unique_ptr<Light>> &lights, int times, WorldObject *ignore) {
	if (times == 0) {
		return vec3();
	}

	WorldObject *hitObject = nullptr;
	vec3 color;
	double t;

	if (trace(hitObject, t, objects, ignore)) {
		if (hitObject != nullptr) {
			vec3 hitPoint = dir * t + pos;
			vec3 normal = (hitPoint - hitObject->pos).normalize();

			std::vector<std::unique_ptr<Light>>::iterator iter = lights.begin();
			for (; iter != lights.end(); iter++) {
				color += (*iter)->applyShading(hitObject->color, hitPoint, normal);
			}

			Ray reflectionRay(hitPoint, dir.normalize().reflect(normal));
			vec3 reflectionColor = reflectionRay.cast(objects, lights, times - 1, hitObject);
			if (reflectionColor.x != 0.0 && reflectionColor.y != 0.0 && reflectionColor.z != 0.0) {
				return reflectionColor * color;
			}
		}
	}

	return color;
}

bool Ray::trace(WorldObject *&hitObject, double &t, std::vector<std::unique_ptr<WorldObject>> &objects, WorldObject *ignore) {
	t = DBL_MAX;
	std::vector<std::unique_ptr<WorldObject>>::iterator iter = objects.begin();

	for (; iter != objects.end(); iter++) {
		double tTmp = DBL_MAX;
		if ((*iter)->intersects(*this, tTmp) && iter->get() != ignore && tTmp < t) {
			t = tTmp;
			hitObject = iter->get();
		}
	}

	if (hitObject != nullptr) {
		return true;
	}

	return false;
}



/*
#include "ray.h"

Ray::Ray() { }

Ray::Ray(vec3 pos, vec3 dir) {
    this->pos = pos;
    this->dir = dir;
}

vec3 Ray::cast(std::vector<std::unique_ptr<WorldObject>> &objects, std::vector<std::unique_ptr<Light>> &lights, int times) {
	if (times == 0) {
		return vec3();
	}

    const WorldObject *hitObject = nullptr;
    vec3 color;
    double t;

    if (trace(hitObject, t, objects) && hitObject != nullptr) {
        vec3 hitPoint = dir * t + pos;
        vec3 normal = (hitPoint - hitObject->pos).normalize();

        std::vector<std::unique_ptr<Light>>::iterator iter = lights.begin();
        for (; iter != lights.end(); iter++) {
            color += (*iter)->applyShading(hitObject->color, hitPoint, normal);
        }

		Ray reflectionRay(hitPoint + normal, dir.reflect(normal).normalize());
		vec3 reflectionColor = reflectionRay.cast(objects, lights, times - 1);
		if (reflectionColor.x != 0.0 && reflectionColor.y != 0.0 && reflectionColor.z != 0.0) {
			return color * reflectionColor;
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
*/
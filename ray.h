#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
public:
    vec3 pos;
    vec3 dir;

    Ray(vec3 pos, vec3 dir);
};

#endif // RAY_H

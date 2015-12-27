#ifndef GLOBALLIGHT_H
#define GLOBALLIGHT_H

#include <algorithm>

#include "light.h"

class GlobalLight : public Light
{
public:
    GlobalLight(vec3 pos, vec3 color);
    GlobalLight(vec3 pos, vec3 color, double radius);
    vec3 applyShading(vec3 fragColor, vec3 fragPos, vec3 normal);
};

#endif // GLOBALLIGHT_H

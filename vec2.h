#ifndef VEC2_H
#define VEC2_H

#include <iostream>
#include <math.h>

class vec2 {
public:
    double x, y;

    vec2();
    vec2(double x, double y);
    double length();
    vec2 normalize();

    // Operators
    vec2 operator+(const vec2& a);
    vec2 operator-(const vec2& b);
    double operator*(const vec2& b);
    vec2& operator+=(const vec2& b);
    vec2& operator-=(const vec2& b);
    friend std::ostream& operator<<(std::ostream& out, const vec2& a);
};

#endif // VEC2_H

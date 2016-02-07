#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>

class vec3 {
public:
    double x, y, z;

    vec3();
    vec3(double x, double y, double z);
    double length();
    vec3 normalize();
    double dot(vec3 b);
    vec3 reflect(vec3 normal);


    // Operators
    friend vec3 operator+(const vec3& a, const vec3& b);
    friend vec3 operator-(const vec3& a, const vec3& b);
    friend vec3 operator*(const vec3& a, const vec3& b);
    friend vec3 operator*(const vec3& a, const double c);
    friend vec3 operator*(const double c, const vec3& a);
    friend vec3 operator/(const vec3& a, const vec3& b);
    friend vec3 operator/(const vec3& a, const double c);
    friend vec3 operator/(const double c, const vec3& a);
    vec3& operator+=(const vec3& b);
    vec3& operator-=(const vec3& b);
    friend std::ostream& operator<<(std::ostream& out, const vec3& a);
};

#endif // VEC3_H

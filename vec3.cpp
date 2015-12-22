#include "vec3.h"

vec3::vec3() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

vec3::vec3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double vec3::length() {
    return sqrt(x * x + y * y + z * z);
}

vec3 vec3::normalize() {
    double len = length();
    return vec3(x / len, y / len, z / len);
}



// Operators
vec3 vec3::operator+(const vec3& a) {
    return vec3(x + a.x, y + a.y, z + a.z);
}

vec3 vec3::operator-(const vec3& b) {
    return vec3(x - b.x, y - b.y, z - b.z);
}

double vec3::operator*(const vec3& b) {
    return x * b.x + y * b.y + z * b.z;
}

vec3& vec3::operator+=(const vec3& a) {
    x += a.x;
    y += a.y;
    z += a.z;
    return *this;
}

vec3& vec3::operator-=(const vec3& a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const vec3& a) {
    return out << "x: " << a.x << " y: " << a.y << " z: " << a.z;
}

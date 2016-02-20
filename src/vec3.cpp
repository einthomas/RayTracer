#include "vec3.h"

vec3::vec3() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

vec3::vec3(double d) {
	x = d;
	y = d;
	z = d;
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

double vec3::dot(vec3 b) {
    return x * b.x + y * b.y + z * b.z;
}

vec3 vec3::cross(vec3 b) {
	return vec3(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
}

vec3 vec3::reflect(vec3 normal) {
    return *this - 2.0 * normal.dot(*this) * normal;
}


// Operators
vec3 operator+(const vec3& a, const vec3& b) {
    return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

vec3 operator-(const vec3& a, const vec3& b) {
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

vec3 operator*(const vec3& a, const vec3& b) {
    return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
}

vec3 operator*(const vec3& a, const double c) {
    return vec3(a.x * c, a.y * c, a.z * c);
}

vec3 operator*(const double c, const vec3& a) {
    return vec3(a.x * c, a.y * c, a.z * c);
}

vec3 operator/(const vec3& a, const vec3& b) {
    return vec3(a.x / b.x, a.y / b.y, a.z / b.z);
}

vec3 operator/(const vec3& a, const double c) {
    return vec3(a.x / c, a.y / c, a.z / c);
}

vec3 operator/(const double c, const vec3& a) {
    return vec3(a.x / c, a.y / c, a.z / c);
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

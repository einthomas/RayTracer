#include "vec2.h"

vec2::vec2() {
    x = 0.0;
    y = 0.0;
}

vec2::vec2(double x, double y) {
    this->x = x;
    this->y = y;
}

double vec2::length() {
    return sqrt(x * x + y * y);
}

vec2 vec2::normalize() {
    double len = length();
    return vec2(x / len, y / len);
}



// Operators
vec2 vec2::operator+(const vec2& a) {
    return vec2(x + a.x, y + a.y);
}

vec2 vec2::operator-(const vec2& b) {
    return vec2(x - b.x, y - b.y);
}

double vec2::operator*(const vec2& b) {
    return x * b.x + y * b.y;
}

vec2& vec2::operator+=(const vec2& a) {
    x += a.x;
    y += a.y;
    return *this;
}

vec2& vec2::operator-=(const vec2& a) {
    x -= a.x;
    y -= a.y;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const vec2& a) {
    return out << "x: " << a.x << " y: " << a.y;
}

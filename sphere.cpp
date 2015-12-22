#include "sphere.h"

Sphere::Sphere(vec3 pos, vec3 color, double radius) {
    this->pos = pos;
    this->color = color;
    this->radius = radius;
    radius2 = radius * radius;
}

/*
 * Equation of a sphere (algebraic)
 * x^2 + y^2 + z^2 = R^2
 * R ... Radius
 * Which means that there's a set of points which solve the equation.
 * Those points define the sphere.
 *
 * Simplified:
 * x, y, z are the coordinates of P
 * P^2 = R^2
 * P^2 - R^2 = 0
 *
 * A ray can be expressed using the parametric form kx + d <-> O + tD
 * O ... Ray origin
 * D ... Ray direction
 * Replace P with the equation of the ray:
 * (O + tD)^2 - R^2 = 0
 * O^2 + 2ODt + (tD)^2 - R^2 = 0
 * (Dt)^2 + 2ODt + O^2 = 0       <->     ax^2 + bx + c = 0
 * a = D^2, b = 2OD, c = O^2
 *
 * Therefore the quadratic formula can be used to solve the equation:
 * (-b +- sqrt(b^2 - 4ac)) / 2a
 */
bool Sphere::intersects(Ray &ray, double &t) {
    vec3 l = ray.pos - pos;
    double a = ray.dir * ray.dir;
    double b = 2 * (ray.dir * l);
    double c = l * l - radius2;

    double t0, t1;
    if (!MyMath::solveQuadratic(a, b, c, t0, t1)) {
        return false;
    }

    if (t0 > t1) {
        std::swap(t0, t1);
    }

    if (t0 < 0) {       // intersection point t0 is behind the origin of the ray
        t0 = t1;
        if (t1 < 0) {   // both intersection points are behind the origin of the ray
            return false;
        }
    }

    t = t0;     // distance from the ray origin to the intersected point

    return true;
}

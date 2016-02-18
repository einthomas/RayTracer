#include "plane.h"

Plane::Plane() {
}

Plane::Plane(vec3 pos, vec3 normal, vec3 color) {
	this->pos = pos;
	this->normal = normal.normalize();
	this->color = color;
	visible = true;
}

/*
 * Equation of a plane:
 * n * (p - p0) = 0
 * * ... dot product
 * p, p0 ... points on the plane
 * n ... normal vector of the plane
 *
 * Parametric form of the ray:
 * l0 + l * t = p
 * l0 ... origin of the ray
 * l ... direction of the ray
 * t ... some number
 *
 * If the ray and the plane intersect, then
 * n * (l0 + l * t - r0) = 0		(some point "on" the ray lies on the plane)
 *
 * Solve for t to get that point:
 * t = ((p0 - l0) * n) / (l * n)
 * * ... dot product
 *
 * if t < 0 -> hit point lies behind the ray origin
 */
bool Plane::intersects(Ray ray, double& t) {
	double t_ = (pos - ray.pos).dot(normal) / (ray.dir.dot(normal));
	if (t_ > 0.0) {
		t = t_;
		return true;
	}

	return false;
}

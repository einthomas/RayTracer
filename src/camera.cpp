#include "camera.h"

Camera::Camera(vec3 eyePos, double fov) {
	this->eyePos = eyePos;
	this->fov = fov;

	up = vec3(0.0f, 1.0f, 0.0f);

	z = (eyePos - lookAt).normalize();
	x = (up.cross(z)).normalize();
	y = z.cross(x);
}

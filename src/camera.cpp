#include "camera.h"

Camera::Camera(vec3 eyePos, vec3 lookAt, double fov) {
	this->eyePos = eyePos;
	this->lookAt = lookAt;
	this->fov = fov;

	up = vec3(0.0f, 1.0f, 0.0f);

	zAxis = (eyePos - lookAt).normalize();
	xAxis = (up.cross(zAxis)).normalize();
	yAxis = zAxis.cross(xAxis);
}

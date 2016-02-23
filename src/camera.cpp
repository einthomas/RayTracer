#include "camera.h"

Camera::Camera(vec3 eyePos, vec3 lookAt, double rollAngle) {
	this->eyePos = eyePos;
	this->lookAt = lookAt;
	this->rollAngle = rollAngle;

	up = vec3(0.0f, 1.0f, 0.0f);
	Mat4<float> rot;
	rot = Mat4<float>::rotate(rot, vec3(0.0f, 0.0f, 1.0f), rollAngle);
	//rot = Mat4<float>::rotate(rot, vec3(0.0f, 0.0f, 1.0f), MyMath::degToRad(30.0f));
	//rot = Mat4<float>::rotate(rot, vec3(0.0f, 0.0f, 1.0f), MyMath::degToRad(90));
	//rot = Mat4<float>::rotate(rot, vec3(0.0f, 1.0f, 0.0f), MyMath::degToRad(30));
	//rot = Mat4<float>::rotate(rot, vec3(0.0f, 0.0f, 1.0f), MyMath::degToRad(90));
	//up = rot * up;

	zAxis = (eyePos - lookAt).normalize();
	xAxis = (up.cross(zAxis)).normalize();
	yAxis = zAxis.cross(xAxis);

	xAxis = rot * xAxis;
	yAxis = rot * yAxis;
	zAxis = rot * zAxis;
}

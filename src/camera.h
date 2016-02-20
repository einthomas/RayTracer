#ifndef CAMERA_H
#define CAMERA_H

#include <vector>

#include "vec2.h"
#include "vec3.h"
#include "worldobject.h"
#include "light.h"

class Camera {
public:
	Camera(vec3 eyePos, double fov);
	virtual std::vector<vec3> render(std::vector<std::unique_ptr<WorldObject>> &objects,
		                             std::vector<std::unique_ptr<Light>> &lights,
									 vec2 imageSize, double imageAspectRatio, int aaDepth) = 0;

protected:
	vec3 eyePos;
	vec3 lookAt;
	vec3 up;
	vec3 x, y, z;		// ONB
	double fov;
};

#endif // CAMERA_H

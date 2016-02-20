#ifndef ORTHOGRAPHIC_H
#define ORTHOGRAPHIC_H

#include "camera.h"

class Orthographic : public Camera {
public:
	Orthographic(vec3 eyePos, double fov);
	std::vector<vec3> render(std::vector<std::unique_ptr<WorldObject>> &objects,
							 std::vector<std::unique_ptr<Light>> &lights,
							 vec2 imageSize, double imageAspectRatio, int aaDepth);
};

#endif // ORTHOGRAPHIC_H

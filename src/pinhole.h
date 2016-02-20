#ifndef PINHOLE_H
#define PINHOLE_H

#include "camera.h"

class Pinhole : public Camera {
public:
	Pinhole(vec3 eyePos, double fov);
	std::vector<vec3> render(std::vector<std::unique_ptr<WorldObject>> &objects,
						  	 std::vector<std::unique_ptr<Light>> &lights,
							 vec2 imageSize, double imageAspectRatio, int aaDepth);
};

#endif // PINHOLE_H

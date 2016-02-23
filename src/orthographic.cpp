#include "orthographic.h"

Orthographic::Orthographic(vec3 eyePos, vec3 lookAt, double fov)
	: Camera(eyePos, lookAt, 0.0f) {
	this->fov = fov;
}

Orthographic::Orthographic(vec3 eyePos, vec3 lookAt, double fov, double rollAngle)
	: Camera(eyePos, lookAt, rollAngle) {
	this->fov = fov;
}

std::vector<vec3> Orthographic::render(std::vector<std::unique_ptr<WorldObject>> &objects,
									   std::vector<std::unique_ptr<Light>> &lights,
									   vec2 imageSize, double imageAspectRatio, int aaDepth) {
	std::vector<vec3> frameBuffer;
	for (int y = 0; y < imageSize.y; y++) {
		for (int x = 0; x < imageSize.x; x++) {
			vec3 pixel;
			std::vector<vec3> aaData;
			for (int aay = 0; aay < aaDepth; aay++) {
				for (int aax = 0; aax < aaDepth; aax++) {
					// normalize ray pos (-> NDC)
					// add 0.5 so that the final ray passes through the middle of the pixel
					pixel.x = (x + ((1.0 / (aaDepth - 1.0)) * aax)) / imageSize.x;
					pixel.y = (y + ((1.0 / (aaDepth - 1.0)) * aay)) / imageSize.y;

					// map from [0;1] to [-imageAspectRatio;imageAspectRatio]
					pixel.x = 2.0 * pixel.x - 1.0;
					pixel.x *= imageAspectRatio;
					pixel.y = 1.0 - 2.0 * pixel.y;

					double scale = tan(MyMath::degToRad(fov / 2.0));
					pixel.x *= scale;
					pixel.y *= scale;

					vec3 rayOrig(-pixel.x, -pixel.y, 0.0f);
					vec3 rayDir(0.0f, 0.0f, -1.0f);
					rayDir -= rayOrig;
					rayDir = rayDir.normalize();

					Ray ray(rayOrig, rayDir);
					aaData.push_back(ray.cast(objects, lights, 3));
				}
			}

			vec3 sum;
			for (vec3 color : aaData) {
				sum += color;
			}
			sum = sum / aaData.size();
			frameBuffer.push_back(sum);
		}
	}

	return frameBuffer;
}

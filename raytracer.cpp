#include "raytracer.h"

RayTracer::RayTracer(vec2 imageSize) {
    this->imageSize = imageSize;
    imageAspectRatio = imageSize.x / imageSize.y;
}

void RayTracer::render(std::vector<std::unique_ptr<WorldObject>> &objects,
                       std::vector<std::unique_ptr<Light>> &lights, double fov) {
    std::cout << "rendering..." << std::endl;
    std::clock_t timer = std::clock();
    std::vector<vec3> frameBuffer;

    for (int y = 0; y < imageSize.y; y++) {
        for (int x = 0; x < imageSize.x; x++) {
            vec3 pixel;

            // normalize ray pos (-> NDC)
            // add 0.5 so that the final ray passes through the middle of the pixel
            pixel.x = (x + 0.5) / imageSize.x;
            pixel.y = (y + 0.5) / imageSize.y;

            // map from [0;1] to [-imageAspectRatio;imageAspectRatio]
            pixel.x = 2.0 * pixel.x - 1.0;
            pixel.x *= imageAspectRatio;
            pixel.y = 1.0 - 2.0 * pixel.y;

            double scale = tan(MyMath::degToRad(fov / 2.0));
            pixel.x *= scale;
            pixel.y *= scale;

            vec3 rayOrig;
            vec3 rayDir(pixel.x, pixel.y, -1.0);
            rayDir -= rayOrig;
            rayDir = rayDir.normalize();

            Ray ray(rayOrig, rayDir);
            frameBuffer.push_back(ray.cast(objects, lights));
        }
    }

    double duration = (std::clock() - timer) / (double)CLOCKS_PER_SEC;
    std::cout << "finished after " << duration << "s" << std::endl;

    std::cout << "writing file..." << std::endl;
    saveToFile("out", frameBuffer);

    std::cout << "writing log..." << std::endl;
    writeLogFile(duration);
}

void RayTracer::saveToFile(std::string filename, std::vector<vec3> frameBuffer) {
    std::ofstream ofs(filename + ".ppm", std::ios::out | std::ios::binary);
    ofs << "P6\n" << imageSize.x << " " << imageSize.y << "\n255\n";

    for (int i = 0; i < imageSize.x * imageSize.y; ++i) {
        char r = (char)(255 * MyMath::clamp(frameBuffer[i].x, 0, 1));
        char g = (char)(255 * MyMath::clamp(frameBuffer[i].y, 0, 1));
        char b = (char)(255 * MyMath::clamp(frameBuffer[i].z, 0, 1));
        ofs << r << g << b;
    }

    ofs.close();
}

void RayTracer::writeLogFile(double duration)
{
    std::ofstream logFile;
    logFile.open("log.txt");
    logFile << "picture size: " << imageSize.x << " x " << imageSize.y << "\n";
    logFile << "render time: " << duration << "s" << "\n";
    logFile.close();
}

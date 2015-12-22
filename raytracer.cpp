#include "raytracer.h"

RayTracer::RayTracer(vec2 imageSize) {
    this->imageSize = imageSize;
}

void RayTracer::render(std::vector<WorldObject> objects) {
    std::clock_t timer = std::clock();
    std::vector<vec3> frameBuffer;

    for (int y = 0; y < imageSize.y; y++) {
        for (int x = 0; x < imageSize.x; x++) {
        }
    }

    double duration = (std::clock() - timer) / (double)CLOCKS_PER_SEC;
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

#include "raytracer.h"

RayTracer::RayTracer(vec2 imageSize) {
    this->imageSize = imageSize;
    imageAspectRatio = imageSize.x / imageSize.y;
}

void RayTracer::render(std::vector<std::unique_ptr<WorldObject>> &objects,
                       std::vector<std::unique_ptr<Light>> &lights, Camera *camera) {
    std::cout << "rendering..." << std::endl;
    std::clock_t timer = std::clock();
    std::vector<vec3> frameBuffer;
    int aaDepth = 4;
	frameBuffer = camera->render(objects, lights, imageSize, imageAspectRatio, aaDepth);

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

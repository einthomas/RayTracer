#include "globallight.h"

GlobalLight::GlobalLight(vec3 pos, vec3 color)
    : Light(pos, vec3(), color) {
}

GlobalLight::GlobalLight(vec3 pos, vec3 color, double radius)
    : Light(pos, vec3(), color, radius) {
}

vec3 GlobalLight::applyShading(vec3 fragColor, vec3 fragPos, vec3 normal) {
    // ambient
    double ambientStrength = 0.03;
    vec3 ambient = color * ambientStrength;

    // diffuse
    vec3 lightDir = pos - fragPos;
    lightDir = lightDir.normalize();

    vec3 diffuse = color * std::max(0.0, normal.dot(lightDir));

    // specular
    double specularStrength = 0.3;
    double shininess = 16.0;
    vec3 viewDir = vec3() - fragPos;
    viewDir = viewDir.normalize();
    lightDir = lightDir * -1;
    vec3 reflection = lightDir.reflect(normal);

    vec3 specular = color * pow(std::max(0.0, reflection.dot(viewDir)), shininess) * specularStrength;

    return fragColor * (ambient + diffuse + specular);
}

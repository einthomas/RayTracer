#include "mymath.h"

const double MyMath::PI = 3.14159265359f;

double MyMath::degToRad(double deg) {
    return deg * MyMath::PI / 180.0f;
}

double MyMath::radToDeg(double rad) {
    return rad * 180 / MyMath::PI;
}

double MyMath::clamp(double n, double lower, double upper) {
    return std::max(lower, std::min(n, upper));
}

/*
 * Solves the quadratic formula
 * (-b +- sqrt(b^2 - 4ac)) / 2a
 *
 * The more stable variant of the formula is used
 * https://en.wikipedia.org/wiki/Loss_of_significance#A_better_algorithm
 * q = -0.5 * (b + sign(b) * sqrt(b^2 - 4ac))
 * x0 = q/a
 * x1 = c/q
 */
bool MyMath::solveQuadratic(const double& a, const double& b, const double& c, double& x0, double& x1) {
    double discriminant = (b * b) - (4 * a * c);

    if (discriminant < 0.0) {       // there's no root
        return false;
    } else if (discriminant == 0.0) {   // there's one root (x0 = x1)
        double q = -0.5 * b;
        x0 = q / a;
        x1 = x0;
    } else {        // there are two roots (x0, x1)
        double q = (b > 0.0f) ?
           -0.5f * (b + sqrt(discriminant)) :
           -0.5f * (b - sqrt(discriminant));
        x0 = q / a;
        x1 = c / q;
    }

    if (x0 > x1) {
        std::swap(x0, x1);
    }

    return true;
}

#ifndef MYMATH_H
#define MYMATH_H

#include <algorithm>

class MyMath
{
public:
    static double degToRad(double deg);
    static double radToDeg(double rad);
    static double clamp(double n, double lower, double upper);
    static bool solveQuadratic(const double& a, const double& b, const double& c, double& x0, double& x1);

private:
    static const double MyMath::PI;
};

#endif // MYMATH_H

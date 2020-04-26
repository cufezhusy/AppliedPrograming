#ifndef H_EXP_5_1
#define H_EXP_5_1

#include <cmath>
#include <iostream>

void ffff(double r, double theta,double* pReal,double* pImaginary)
{
    *pReal = r*cos(theta);
    *pImaginary = r*sin(theta);
}

int example_5_1(double r, double theta)
{
    double x, y;
    ffff(r, theta, &x, &y);
    std::cout << "Real part = " << x << "\n";
    std::cout << "Imaginary part = " << y << "\n";
    return 0;
}

#endif
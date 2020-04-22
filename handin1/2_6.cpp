#ifndef H_2_6_H
#define H_2_6_H
#include <cmath>
#include <iostream>

double f(double x)
{
    return exp(x) + pow(x,3) -5;
}

double df(double x)
{
    return exp(x) + 3 * pow(x,2);
}


double newton_Raphson(double initialGuess, double epsilon)
{
    double x,dx;
    x = initialGuess;
    do {
        dx = f(x) /df(x);
        x = x- dx;
    }
    while (abs(dx)>epsilon);
    return x;
}


#endif
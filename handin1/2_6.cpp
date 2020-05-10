#ifndef H_2_6_H
#define H_2_6_H
#include <cmath>
#include <iostream>

double f(double x);
double df(double x);


double newton_Raphson(double initialGuess, double epsilon)
{
    double x,dx;
    x = initialGuess;
    do {
        dx = f(x) /df(x);
        x = x- dx;
        std:: cout <<  "x =" << x << " , dx=" << dx << "\n";
    }
    while (abs(dx)>epsilon);
    
    std:: cout <<  "x =" << x << " , f(x)=" << f(x) << "\n";
    return x;
}

double f(double x)
{
    return exp(x) + pow(x,3) -5;
}

double df(double x)
{
    return exp(x) + 3 * pow(x,2);
}


#endif
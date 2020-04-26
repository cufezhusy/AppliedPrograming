#ifndef TEST_5_4
#define TEST_5_4
#include <cmath>


double calc_mean(double a[], int length)
{
    double mean = 0.0;
    for (int i = 0; i<length; i++)
    {
        mean +=a[i];
    }
    mean = mean / length;
    return mean;
}

double calc_std(double a[], int length)
{
    double squared_sum = 0.0;
    double std;
    double mean = calc_mean(a,length);
    if (length >1) 
    {    
        for (int i = 0; i<length; i++)
        {
            squared_sum += pow(a[i] - mean,2);
        }
        std = sqrt(squared_sum/((float) length -1));
    }
    else
    {
        std = 0.0;
    }
    
    return std;
}

#endif

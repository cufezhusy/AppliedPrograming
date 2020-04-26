#ifndef TEST_5_6
#define TEST_5_6

#include <cassert>

void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols)
{
    assert (ACols == BRows);
    double temp_sum;
    for (int i = 0; i< BCols; i ++)
    {
        temp_sum = 0.0;
        for (int j=0; j<ACols; j++)
        {
            temp_sum += A[j] * B[j][i];
        }
        res[i] = temp_sum;
    }
}


void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols)
{
    assert (ACols == BRows);
    for (int i =0; i< ARows; i ++)
    {
        double * temp_res = new double[ACols];
        Multiply(temp_res,A[i],B,ACols,BRows,BCols);
        res[i] = temp_res;
        delete [] temp_res;
    }
}

void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows)
{
    assert (ACols == BRows);
    double temp_sum;
    for (int i = 0; i< ARows; i ++)
    {
        temp_sum = 0.0;
        for (int j=0; j<ACols; j++)
        {
            temp_sum += A[i][j] * B[j];
        }
        res[i] = temp_sum;
    }


}

void Multiply(double **res, double scalar, double **B, int BRows, int BCols)
{
    for (int i = 0; i< BRows; i ++)
   {
       for (int j = 0; j< BCols; j ++)
       {
           res[i][j] = scalar * B[i][j];
       }
   }
}

void Multiply(double **res, double **B, double scalar, int BRows, int BCols)
{
   Multiply(res,scalar,B,BRows,BCols);
}

#endif

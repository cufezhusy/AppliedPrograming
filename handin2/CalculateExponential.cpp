#include "CalculateExponential.hpp"
#include <cassert>


void Multiply(ComplexNumber **res, ComplexNumber **A, ComplexNumber **B, int ARows, int ACols, int BRows, int BCols)
{
    assert (ACols == BRows);
    ComplexNumber temp_sum;
    for (int i =0; i< ARows; i ++)
    {
       for (int ii = 0; ii< BCols; ii ++)
        {
            temp_sum = ComplexNumber(0.0,0.0);
            for (int j=0; j<ACols; j++)
            {
                temp_sum = temp_sum + A[i][j] * B[j][ii];
            }
        res[i][ii] = temp_sum;
        }
    }
}


void Add(ComplexNumber **res, ComplexNumber **A, ComplexNumber **B, int ARows, int ACols, int BRows, int BCols)
{
    assert (ARows == BRows);
    assert (ACols == BCols);
    for (int i =0; i< ARows; i ++)
    {
       for (int j = 0; j< ACols; j ++)
        {
           res[i][j] = A[i][j] + B[i][j];
        }
    }
}


void Add(ComplexNumber **res, ComplexNumber **A, ComplexNumber B, int ARows, int ACols)
{
    for (int i =0; i< ARows; i ++)
    {
       for (int j = 0; j< ACols; j ++)
        {
           res[i][j] = A[i][j] + B;
        }
    }
}


void Multiply(ComplexNumber **res, ComplexNumber scalar, ComplexNumber **B, int BRows, int BCols)
{
    for (int i = 0; i< BRows; i ++)
   {
       for (int j = 0; j< BCols; j ++)
       {
           res[i][j] = scalar * B[i][j];
       }
   }
}

ComplexNumber** AllocateMatrixMemory(int numRows, int numCols)
{ 
    ComplexNumber** matrix;
    matrix = new ComplexNumber* [numRows];
    for (int i=0; i<numRows; i++)
    {
      matrix[i] = new ComplexNumber[numCols];
    }
    return matrix;
}

void FreeMatrixMemory (int numRows, ComplexNumber ** matrix)
{
  for (int i =0; i < numRows; i ++)
  {
    delete [] matrix[i];
  }
  delete[] matrix;
}

void CopyMatrix(ComplexNumber **res, ComplexNumber **A, int ARows, int ACols, int BRows, int BCols)
{
    assert (ARows == BRows);
    assert (ACols == BCols);
    for (int i =0; i< ARows; i ++)
    {
       for (int j = 0; j< ACols; j ++)
        {
           res[i][j] = ComplexNumber(A[i][j]);
        }
    }
}

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
    bool debug = false;
    int N = 3;
    ComplexNumber ** A_n = AllocateMatrixMemory(N,N);
    double n_pow;
    n_pow = 1;
    for (int i =0; i< N; i ++)
    {
       for (int j = 0; j< N; j ++)
        {
           if (i==j)
           {
               A_n[i][j] = ComplexNumber(1.0,0.0);
           }
           else
           {
                A_n[i][j] = ComplexNumber(0.0,0.0);
           }
           
        }
    }
    CopyMatrix(res,A_n,N,N,N,N);
    for (int n=1; n<=nMax;n++)
    {
        ComplexNumber ** temp_res = AllocateMatrixMemory(N,N);
        Multiply(temp_res,A_n,A,N,N,N,N);
        CopyMatrix(A_n,temp_res,N,N,N,N);
        n_pow = n_pow * n;
        ComplexNumber z = ComplexNumber(1.0/n_pow,0.0);
        ComplexNumber ** temp_res_2 = AllocateMatrixMemory(N,N);
        Multiply(temp_res_2,z,temp_res,N,N);
        Add(res,res,temp_res_2,N,N,N,N);
        if (debug)
        {
        std::cout << "---- n = " << n << "\n";
        std::cout << "---- n_pow = " << n_pow << "\n";
        std::cout << "temp_res =  \n"; 
        printMatrix(temp_res,N,N) ;
        std::cout << "z = " << z << "\n";
        std::cout << "temp_res_2 =  \n"; 
        printMatrix(temp_res_2,N,N) ;
        }
        FreeMatrixMemory(N,temp_res);
        FreeMatrixMemory(N,temp_res_2);
    }
    FreeMatrixMemory(N,A_n);
}

void printMatrix(ComplexNumber **A, int rows, int cols)
{
  for (int i=0; i<rows; i++)
  {
    for (int j=0; j<cols; j++)
    {
      std:: cout << A[i][j] << " ";
    }
    std:: cout << "\n";
  }
}
#ifndef H_5_10_H
#define H_5_10_H
#include <iostream>
#include "5_6.cpp"

double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory (int numRows, double ** matrix);
int findColumnWithLargestAbsoluteValue(double **A, int k, int n);
void PrintMatrix(double **matrix, int numRows, int numCols);
void p_matrix(double **P, int n, int k, int nn);
void m_matrix(double **M, double **A, int n, int k );


void guassian_elimination(double **A, double *b, double *u, int n)
{
    int nn, ss;
    double ** P = AllocateMatrixMemory(n , n);
    double ** M = AllocateMatrixMemory(n , n);
    double ** Ak = AllocateMatrixMemory(n , n);
    double* bk = new double [3];
    for (int k =0; k <n; k++)
    {   
        std:: cout << "k = " << k << "\n";
        nn = findColumnWithLargestAbsoluteValue( A, k, n);
        std:: cout << "nn = " << nn << "\n";
        p_matrix(P,n,k,nn);
        std:: cout << "P = " << "\n";
        PrintMatrix(P,n,n);
        Multiply(Ak,P,A,n,n,n,n);
        std:: cout << "A = " << "\n";
        PrintMatrix(Ak,n,n);
        Multiply(bk,P,b,n,n,n);
        m_matrix(M,Ak,n,k);
        std:: cout << "M = " << "\n";
        PrintMatrix(M,n,n);
        Multiply(A,M,Ak,n,n,n,n);
        Multiply(b,M,bk,n,n,n);
        std:: cout << "A = " << "\n";
        PrintMatrix(A,n,n);
    }

    std:: cout << "bk = " << "\n";
    for (int i = 0; i <n ; i++)
    {
        std:: cout << bk[i] << " ";
    }
    std:: cout << "\n";

    for (int i=n-1; i>=0; i--)
    {
        double sum ;
        sum = 0.0;
        for (int j = n-1; j>i; j--)
        {
            sum +=u[j] * A[i][j];
        }
        u[i] = (bk[i] - sum)/ A[i][i];
    }

    FreeMatrixMemory(n, P);
    FreeMatrixMemory(n, M);
    FreeMatrixMemory(n, Ak);
    delete [] bk;
}


void PrintMatrix(double **matrix, int numRows, int numCols)
{
  for (int i=0; i<numRows; i++)
  {
    for (int j=0; j<numCols; j++)
    {
      std:: cout << matrix[i][j] << " ";
    }
    std:: cout << "\n";
  }
}

int findColumnWithLargestAbsoluteValue(double **A, int k, int n)
{
    double max;
    max = 0.0;
    int out = k;
    for (int nn = k; nn < n; nn++)
    {
        if (abs(A[nn][k]) > max)
        {
            out = nn;
            max = abs(A[nn][k]);
        }
    }
    return out;
}

void p_matrix(double **P, int n, int k, int nn)
{
    for (int i =0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {
            if ((i == j) && (i!=k) && (j!=k) && (i!=nn) && (j!=nn))
            {
                P[i][j] = 1;
            }
            else if ((i== k) & (j==nn))
            {
                P[i][j] = 1;
            }
            else if ((i== nn) & (j==k))
            {
                P[i][j] = 1;
            }
            else
            {
                P[i][j] = 0;
            }
            
        }
    }
}


void m_matrix(double **M, double **A, int n, int k )
{
    for (int i =0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {
            if (i == j) 
            {
                M[i][j] = 1;
            }
            else if ((j ==k) & (i>k) )
            {
                M[i][j] = -A[i][j]/A[k][k];
            }
            else
            {
                M[i][j] = 0;
            }
            
        }
    }

}

double** AllocateMatrixMemory(int numRows, int numCols)
{ 
    double** matrix;
    matrix = new double* [numRows];
    for (int i=0; i<numRows; i++)
    {
      matrix[i] = new double [numCols];
    }
    return matrix;
}

void FreeMatrixMemory (int numRows, double ** matrix)
{
  for (int i =0; i < numRows; i ++)
  {
    delete [] matrix[i];
  }
  delete[] matrix;
}



#endif



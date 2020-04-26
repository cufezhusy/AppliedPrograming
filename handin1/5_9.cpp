#ifndef H_5_10_H
#define H_5_10_H
#include <iostream>
#include <cassert>
double determinant2D(double **A);
int start_index(int a);
int end_index(int a);
double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory (int numRows, double ** matrix);
void PrintMatrix(double **matrix, int numRows, int numCols);
double** calculateADet(double **A);
double** cofactorsMatrix(double **matrix);
double** adjointMatrix(double **matrix);
void Multiply(double **res, double scalar, double **B, int BRows, int BCols) ;
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows);

void solve3by3(double **A, double *b, double *u)
{   
    //PrintMatrix(A,3,3);
    // Calculate Determinat for each element
    double** A_det = calculateADet(A);
    //PrintMatrix(A_det,3,3);
    double** A_cofactors = cofactorsMatrix(A_det);
    //PrintMatrix(A_det_correct,3,3);
    double** A_adjoint = adjointMatrix(A_cofactors);
    //PrintMatrix(A_adjoint,3,3);

    double determinant = 0.0;
    for (int j=0;j<3;j++)
    {
        determinant+=A[0][j] * A_cofactors[0][j];
    }

    double** A_inverse = AllocateMatrixMemory(3,3);
    Multiply(A_inverse,1.0/determinant,A_adjoint,3,3);
    //PrintMatrix(A_inverse,3,3);
    Multiply(u,A_inverse,b,3,3,3);

    FreeMatrixMemory(3,A_det);
    FreeMatrixMemory(3,A_cofactors);
    FreeMatrixMemory(3,A_adjoint);
    FreeMatrixMemory(3,A_inverse);
    
}

double** calculateADet(double **A)
{
    double** A_det = AllocateMatrixMemory(3,3);
    for (int i=0;i<3;i++)
    {
        int start_i = start_index(i);
        int end_i = end_index(i);
        for (int j=0;j<3;j++)
        {   
            int start_j = start_index(j);
            int end_j = end_index(j);
            double** temp_2d = AllocateMatrixMemory(2,2);
            temp_2d[0][0] = A[start_i][start_j];
            temp_2d[0][1] = A[start_i][end_j];
            temp_2d[1][0] = A[end_i][start_j];
            temp_2d[1][1] = A[end_i][end_j];
            A_det[i][j] = determinant2D(temp_2d);
            FreeMatrixMemory(2,temp_2d);
        }
    }
    return A_det;
}

double** cofactorsMatrix(double **matrix)
{
    double** out = AllocateMatrixMemory(3,3);
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {   
            if ((i != j) && (i+j !=2))
            {
                out[i][j] = -matrix[i][j];
            }
            else
            {
                out[i][j] = matrix[i][j];
            }
            
        }
    }
    return out;
}


double determinant2D(double **matrix)
{
    return matrix[0][0] * matrix[1][1] - matrix[0][1]*matrix[1][0];
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

double** adjointMatrix(double **matrix)
{
    double** out = AllocateMatrixMemory(3,3);
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {   
            if (i != j)
            {
                out[i][j] = matrix[j][i];
            }
            else
            {
                out[i][j] = matrix[i][j];
            }
            
        }
    }
    return out;
}


void FreeMatrixMemory (int numRows, double ** matrix)
{
  for (int i =0; i < numRows; i ++)
  {
    delete [] matrix[i];
  }
  delete[] matrix;
}

int start_index(int a)
{
    if (a == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int end_index(int a)
{
    if (a == 2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
    
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

#endif

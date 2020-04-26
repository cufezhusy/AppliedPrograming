#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include <random>

//#include "./handin1/2_6.h"
//#include "./handin1/3_3.h"
//#include "./handin1/5_3.h"
//#include "./handin1/5_4.h"
#include "./handin1/5_6.h"
//#include "./handin1/5_9.h"
//#include "./handin1/5_10.h"
//#include "./demo/example_5_1.h"


// Some help functions 
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


void AssignRandomValueToMatrix(double **matrix, int numRows, int numCols)
{
  for (int i=0; i<numRows; i++)
  {
    for (int j=0; j<numCols; j++)
    {
      matrix[i][j] = rand() % 10;
    }
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

void PrintVector(double *vector, int numRows)
{
  for (int i=0 ; i<numRows; i++)
  {
    std:: cout << vector[i] << " ";
  }
  std:: cout << "\n";
}

void FreeMatrixMemory (int numRows, double ** matrix)
{
  for (int i =0; i < numRows; i ++)
  {
    delete [] matrix[i];
  }
  delete[] matrix;
}

int main(int argc, char* argv[])

{
	//std::cout << "x = " << x << " and y = " << y << "\n";

  // 2.6 double newton_Raphson(double initialGuess, double epsilon);
  //double newton = newton_Raphson(0,  0.000001);
  //std::cout << newton <<"\n";

  // 3.3
  //std::cout << "euler\n";
  //implicit_Euler(100);

  // 5.3
  //double a = 3, b =2;
  //std::cout << "a = " << a << " and b = " << b << "\n";
  //swap_ref(a,b);
  //std::cout << "a = " << a << " and b = " << b << "\n";

  // pointerfun();
  
  // 5.4
  //double* A = new double [5];
  //A[0] =3; A[1]=2;A[2]=4;A[3]=3;A[4]=6;
  //std::cout << "mean = " << calc_mean(A,5) << "\n";
  //std::cout << "std = " << calc_std(A,5) << "\n";
  //delete [] A;

  //double* B = new double [1];
  //B[0] =3;
  //std::cout << "mean = " << calc_mean(B,1) << "\n";
  //std::cout << "std = " << calc_std(B,1) << "\n";
  //delete [] B;
  // mean();

  // 5.6 Multiply matrix and vectors
  // ...


  double scalar = 10;
  int ARows = 3 ; int ACols = 4;
  double **A = AllocateMatrixMemory(ARows,ACols);
  AssignRandomValueToMatrix(A,ARows,ACols);
  std:: cout << "A = " << "\n";
  PrintMatrix(A,ARows,ACols);
  int BRows = 4 ; int BCols =3;
  double **B = AllocateMatrixMemory(BRows,BCols);
  AssignRandomValueToMatrix(B,BRows,BCols);
  std:: cout << "B = " << "\n";
  PrintMatrix(B,BRows,BCols);

  // Test case 1: scale * matrix
  std:: cout << "========== test case 1 ========== \n";
  double **res_case1 = AllocateMatrixMemory(BRows,BCols);
  
  Multiply(res_case1,scalar,B,BRows,BCols);
  std:: cout << "Result = " << "\n";
  PrintMatrix(res_case1,BRows,BCols);
  FreeMatrixMemory(BRows,B);

   // Test case 2: matrix * vector
   std:: cout << "========== test case 2 ========== \n";
   double* res_case2 = new double [ARows];
   double* b_vector = new double [BRows];
   for (int j = 0; j < BRows; j++)
   {
     b_vector[j] = B[j][0];
   }
   std:: cout << "b_vector = " << "\n";
   PrintVector(b_vector,BRows);
   Multiply(res_case2,A,b_vector,ARows,ACols,BRows);
   std:: cout << "Result = " << "\n";
   PrintVector(res_case2,ARows);

  // Test case 4: matrix * matrix
  std:: cout << "========== test case 3 ========== \n";
  double* res_case3 = new double [BCols];
  Multiply(res_case3,A[0],B,ACols,BRows,BCols);
  std:: cout << "Result = " << "\n";
  PrintVector(res_case3,BCols);

  // Test case 4: matrix * matrix
  std:: cout << "========== test case 4 ========== \n";
  double** res_case4 = AllocateMatrixMemory(ARows,BCols);
  Multiply(res_case4,A,B,ARows,ACols,BRows,BCols);
  std:: cout << "Result = " << "\n";
  PrintMatrix(res_case4,ARows,BCols);
  return 0;
}
#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include <random>

//#include "./handin1/2_6.h"
//#include "./handin1/3_3.h"
//#include "./handin1/5_3.h"
//#include "./handin1/5_4.h"
//#include "./handin1/5_6.h"
//#include "./handin1/5_9.h"
#include "./handin1/5_10.h"
//#include "./demo/example_5_1.h"

int main(int argc, char* argv[])

{
	
  double** A = AllocateMatrixMemory(3,3);
  A[0][0] = 3.0; A[0][1] = 0; A[0][2] =2;
  A[1][0] = 2.0; A[1][1] = 0; A[1][2] =-2;
  A[2][0] = 0.0; A[2][1] = 1; A[2][2] =1;

  double* b = new double [3];
  b[0] = 11; b[1] =3; b[2] =4; 

  double* u = new double [3];
  guassian_elimination(A,b,u,3);
  for (int i = 0; i <3 ; i++)
  {
    std:: cout << u[i] << " ";
  }
  std::getchar();
  return 0;
}
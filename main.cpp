#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include <random>

//#include "./handin1/2_6.h"
//#include "./handin1/3_3.h"
//#include "./handin1/5_3.h"
#include "./handin1/5_4.h"
//#include "./handin1/5_6.h"
//#include "./handin1/5_9.h"
//#include "./handin1/5_10.h"
//#include "./demo/example_5_1.h"

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
  double* A = new double [5];
  A[0] =3; A[1]=2;A[2]=4;A[3]=3;A[4]=6;
  std::cout << "mean = " << calc_mean(A,5) << "\n";
  std::cout << "std = " << calc_std(A,5) << "\n";
  delete [] A;

  double* B = new double [1];
  B[0] =3;
  std::cout << "mean = " << calc_mean(B,1) << "\n";
  std::cout << "std = " << calc_std(B,1) << "\n";
  delete [] B;
  // mean();

  // 5.6 Multiply matrix and vectors
  // ...

  return 0;
}
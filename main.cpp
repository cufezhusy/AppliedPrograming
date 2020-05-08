#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include <random>

#include "./handin2/CalculateExponential.hpp"

int main(int argc, char* argv[])

{
	ComplexNumber z1(4.0,3.0);
  std::cout << "z1 = " <<z1 << "\n";
  std::cout << "RealPart = " <<z1.GetRealPart() << "\n";
  std::cout << "ImaginaryPart = " <<z1.GetImaginaryPart() << "\n";
  std::cout << "RealPart = " <<RealPart(z1) << "\n";
  std::cout << "ImaginaryPart = " <<ImaginaryPart(z1) << "\n";
  ComplexNumber z2 = ComplexNumber(z1);
  std::cout << "z2 = " <<z2 << "\n";
  ComplexNumber z3 = z2.CalculateConjugate();
  std::cout << "Conjugate of z2 which is z3 = " <<z3 << "\n";
  ComplexNumber z4 = z2 * z3;
  std::cout << "Z2 * z3 = " <<z4 << "\n";

  ComplexNumber** test_matrix = AllocateMatrixMemory(3,3);
  test_matrix[0][0] = ComplexNumber(0.2,0.1);
  test_matrix[0][1] = ComplexNumber(0.2,0.1);
  test_matrix[0][2] = ComplexNumber(-0.3,0.2);
  test_matrix[1][0] = ComplexNumber(0.2,0);
  test_matrix[1][1] = ComplexNumber(0.1,0.4);
  test_matrix[1][2] = ComplexNumber(0.3,0.1);
  test_matrix[2][0] = ComplexNumber(0.3,0);
  test_matrix[2][1] = ComplexNumber(0.2,0.4);
  test_matrix[2][2] = ComplexNumber(0.4,0.2);
  std::cout << "Test matrix --- \n";
  printMatrix(test_matrix,3,3);
  ComplexNumber** res = AllocateMatrixMemory(3,3);
  CalculateExponential(test_matrix,1000,res);
  std::cout << "Result --- \n";
  printMatrix(res,3,3);
  FreeMatrixMemory(3,test_matrix);
  FreeMatrixMemory(3,res);
  std::getchar();
  return 0;
}
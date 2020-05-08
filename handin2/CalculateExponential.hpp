#ifndef _CALCULATEEXPONENTIAL_
#define _CALCULATEEXPONENTIAL_

#include "ComplexNumber.hpp"

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res);


//non mandatory
void printMatrix(ComplexNumber **A, int rows, int cols);

ComplexNumber** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory (int numRows, ComplexNumber ** matrix);
#endif

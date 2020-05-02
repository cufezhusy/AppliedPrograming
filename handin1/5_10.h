#ifndef H_5_10_H
#define H_5_10_H

void guassian_elimination(double **A, double *b, double *u, int n);
void FreeMatrixMemory (int numRows, double ** matrix);
int findColumnWithLargestAbsoluteValue(double **A, int k, int n);
double** AllocateMatrixMemory(int numRows, int numCols);

#endif

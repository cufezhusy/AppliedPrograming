#ifndef TEST_5_6
#define TEST_5_6

void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols);
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols);
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows);
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

#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include <random>

#include "./handin2/Matrix2x2.hpp"
//#include "./handin1/3_3.h"
//#include "./handin1/5_3.h"
//#include "./handin1/5_4.h"
//#include "./handin1/5_6.h"
//#include "./handin1/5_9.h"
//#include "./handin1/5_10.h"
//#include "./demo/example_5_1.h"

int main(int argc, char* argv[])

{
    Matrix2x2 A = Matrix2x2(0.2,0.3,0.4,0.1);
    A.Print();
    Matrix2x2 B = A.CalcInverse();
    B.Print();
    Matrix2x2 C = A + B;
    C.Print();
    std:: cout << C.Getval00();
    std::getchar();
    return 0;
}
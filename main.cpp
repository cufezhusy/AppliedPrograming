#include <iostream>
#include <sstream>
#include <ctime>
#include "./handin3/Vector.hpp"
#include "./handin3/Matrix.hpp"

int main(int argc, char* argv[])

{   
    std::cout << "-----test for vector ----" << "\n";
    Vector<double> s = Vector<double>(10);
    Vector<double> d = Vector<double>(s);
    s.Print();
    s[3] = 2.0;
    d[4] = 3.0;
    Vector<double> e = s + d;
    e.Print();
    std::cout << e.CalculateNorm() << "\n";

    std::cout << "-----test for matrix ----" << "\n";
    Matrix<double> A = Matrix<double>(4,3);
    A(0,0) = 3.2;
    A(1,0) = 5.4;
    A(3,2) = 9.9;
    std::cout << "A =" << "\n";
    A.Print();
    Matrix<double> B = Matrix<double>(4,3);
    B(0,0) = 5;
    std::cout << "B =" << "\n";
    B.Print();
    Matrix<double> C = A + B;
    std::cout << "C =" << "\n";
    C.Print();
    std::getchar();
    
    return 0;
}
#include <iostream>
#include <sstream>
#include <ctime>
//#include "./handin3/Vector.hpp"
//#include "./handin3/Matrix.hpp"
#include "./handin3/SparseVector.hpp"

int main(int argc, char* argv[])

{   
    std::cout << "-----test start ----" << "\n";
    SparseVector<double> empty_vector = SparseVector<double> ();
    SparseVector<double> a = SparseVector<double> (1000);
    a.setValue(12, 3.2);
    a.setValue(6, 4);
    a.setValue(30, 71);
    a.setValue(12, 9.3);
    a.Print();
    std::cout << "A_10 = " << a.getValue(10) << '\n';
    std::cout << "A_12 = " << a.getValue(12) << '\n';
    std::cout << "A_30 = " << a.getValue(30) << '\n';
    std::cout << "no of non zero eleemnts in A  = " << a.nonZeroes() << '\n';
    std::cout << "Index of 2nd elements  = " << a.indexNonZero(2) << '\n';
    std::cout << "Value of 2nd elements  = " << a.valueNonZero(2) << '\n';
    SparseVector<double> b = SparseVector<double> (1000);
    b.setValue(12,99.0);
    b.setValue(392,12.3);
    b.setValue(1,17.0);
    std::cout << "b=" << "\n";
    b.Print();
    a+=b;
    std::cout << "a=" << "\n";
    a.Print();
    a-=b;
    std::cout << "a=" << "\n";
    a.Print();
    SparseVector<double> c = a + b;
    std::cout << "c= a+b = " << "\n";
    c.Print();
    SparseVector<double> d = a - b;
    std::cout << "d= a-b = " << "\n";
    d.Print();

    SparseVector<double> e = SparseVector<double> (3);
    e.setValue(0,3);
    e.setValue(2,5);
    Matrix<double> A = Matrix<double> (3,3);
    A(0,0) = 1; A(0,1) = 0; A(0,2) = 0;
    A(1,0) = 0; A(1,1) = 1; A(1,2) = 0; 
    A(2,0) = 0; A(2,1) = 0; A(2,2) = 1;
    Vector<double> y = A * e;
    std::cout << " y = A*e = " << "\n";
    y.Print(); 

    Vector<double> y2 = e * A;
    std::cout << " y2 = e*A = " << "\n";
    y2.Print(); 
    std::getchar();
    return 0;
}
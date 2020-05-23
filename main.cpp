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
    std::getchar();
    return 0;
}
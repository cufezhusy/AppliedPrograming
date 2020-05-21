#include <iostream>
#include <sstream>
#include <ctime>
#include "./handin3/Vector.hpp"

int main(int argc, char* argv[])

{
    Vector<double> s = Vector<double>(10);
    Vector<double> d = Vector<double>(s);
    s.Print();
    s[3] = 2.0;
    d[4] = 3.0;
    Vector<double> e = s + d;
    e.Print();
    std::cout << e.CalculateNorm() << "\n";
    std::getchar();
    
    return 0;
}
#include <iostream>
#include <sstream>
#include <ctime>

//#include "./handin2/Matrix2x2.hpp"
#include "./handin2/Student.hpp"
#include "./handin2/GraduateStudent.hpp"
#include "./handin2/PhdStudent.hpp"
//#include "./handin1/3_3.h"
//#include "./handin1/5_3.h"
//#include "./handin1/5_4.h"
//#include "./handin1/5_6.h"
//#include "./handin1/5_9.h"
//#include "./handin1/5_10.h"
//#include "./demo/example_5_1.h"

int main(int argc, char* argv[])

{
    Student shengyao_junoir  = Student("shengyao",0.0,10000);
    PhdStudent shengyao_senior  = PhdStudent("shengyao",0.0,10000,0);
    GraduateStudent shengyao = GraduateStudent("shengyao",0.0,10000.0,0);
    shengyao_junoir.SetLibraryFines(10);
    shengyao.SetLibraryFines(3);
    std::cout << "Shengyao's fine is " << shengyao.GetLibraryFines() << '\n';
    std::cout << "Shengyao junoir s total owed is " << shengyao_junoir.MoneyOwed() << '\n';
    std::cout << "Shengyao's total owed is " << shengyao.MoneyOwed() << '\n';
    std::cout << "Shengyao senior's total owed is " << shengyao_senior.MoneyOwed() << '\n';
    std::getchar();
    return 0;
}
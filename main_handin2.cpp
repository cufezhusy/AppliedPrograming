#include <iostream>
#include <sstream>
#include <ctime>

//#include "./handin2/Matrix2x2.hpp"
#include "./handin2/Student.hpp"
#include "./handin2/Exception.hpp"
//#include "./handin2/GraduateStudent.hpp"
//#include "./handin2/PhdStudent.hpp"
//include "./handin2/OutOfRangeException.hpp"
//#include "./handin1/3_3.h"
//#include "./handin1/5_3.h"
//#include "./handin1/5_4.h"
//#include "./handin1/5_6.h"
//#include "./handin1/5_9.h"
//#include "./handin1/5_10.h"
//#include "./demo/example_5_1.h"

int main(int argc, char* argv[])

{
    Student Shengyao = Student();
    try
    {
        Shengyao.SetLibraryFines(-32.0);
        std::cout << "Fine is :" << Shengyao.GetLibraryFines() << "\n";
    }
    catch(Exception & error)
    {   
        error.PrintDebug();
    }
        std::getchar();
        return 0;
}
#include <iostream>
#include <sstream>
#include <ctime>

//#include "./handin2/Matrix2x2.hpp"
//#include "./handin2/Student.hpp"
//#include "./handin2/GraduateStudent.hpp"
//#include "./handin2/PhdStudent.hpp"
#include "./handin2/OutOfRangeException.hpp"
//#include "./handin1/3_3.h"
//#include "./handin1/5_3.h"
//#include "./handin1/5_4.h"
//#include "./handin1/5_6.h"
//#include "./handin1/5_9.h"
//#include "./handin1/5_10.h"
//#include "./demo/example_5_1.h"

void run()
{
    throw OutOfRangeException("I am an error!");
}

int main(int argc, char* argv[])

{
    try
    {
        run();
    }
    catch(Exception& error)
    {
        error.PrintDebug();
    }

    std::getchar();
    return 0;
}
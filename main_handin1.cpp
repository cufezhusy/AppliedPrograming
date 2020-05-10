#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include <random>

#include "./handin1/2_6.h"
//#include "./handin1/3_3.h"
//#include "./handin1/5_3.h"
//#include "./handin1/5_4.h"
//#include "./handin1/5_6.h"
//#include "./handin1/5_9.h"
//#include "./handin1/5_10.h"
//#include "./demo/example_5_1.h"

int main(int argc, char* argv[])

{
	double x;
  x = newton_Raphson(0,0.00001);
  std:: cout << "x =" << x << "\n";
  std::getchar();
  return 0;
}
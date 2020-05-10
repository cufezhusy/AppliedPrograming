#include "OutOfRangeException.hpp"

OutOfRangeException :: OutOfRangeException(std::string prob)
{
    SetProblem(prob);
    SetTag("Out of Range");
}
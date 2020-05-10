#include "FileNotOpenException.hpp"

FileNotOpenException :: FileNotOpenException(std::string prob)
{
    SetProblem(prob);
    SetTag("File Not Open");
}
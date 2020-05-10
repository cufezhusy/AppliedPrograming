#include <iostream>
#include "Exception.hpp"


Exception :: Exception(std::string tagString, std::string probString)
{
    mTag = tagString;
    mProblem = probString;
}

Exception :: Exception()
{
    mTag = "NA";
    mProblem = "NA";
}


void Exception:: PrintDebug() const
{
    std::cerr << " ** Error ("<< mTag  << ") **\n";
    std::cerr << " ** Problem: "<< mProblem  <<"\n\n";
}

void Exception:: SetTag(std::string tagString)
{
    mTag = tagString;
}

void Exception:: SetProblem(std::string probString)
{
    mProblem = probString;
}
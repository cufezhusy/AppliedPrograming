#include "GraduateStudent.hpp"

GraduateStudent :: GraduateStudent()
{
    fullTime = 1;
}

GraduateStudent :: GraduateStudent (std::string name, double fines, double fees, bool fullTime)
{
    name = name;
    tuition_fees = fees;
    SetLibraryFines(fines);
    fullTime = fullTime;
}

double GraduateStudent :: MoneyOwed() const
{
    return GetLibraryFines();
}
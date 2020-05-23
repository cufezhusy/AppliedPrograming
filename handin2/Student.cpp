# include "Student.hpp"
# include "Exception.hpp"
Student :: Student()
{
    name = "Unknown";
    tuition_fees = 0.0;
    library_fines = 0.0;
}


Student :: Student(std::string name, double fines, double fees)
{
    name = name;
    library_fines = fines;
    tuition_fees = fees;
}

double Student :: MoneyOwed() const
{
    return library_fines + tuition_fees;
}

void Student:: SetLibraryFines(double amount)
{   
    if (amount>=0.0) 
    {
        library_fines = amount;
    }
    else
    {
        std:: cout << "Tution fee cannot be negative";
    }
    
}

double Student:: GetLibraryFines() const
{
    return library_fines;
}

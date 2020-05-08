# include "ComplexNumber.hpp"
# include <cmath>

ComplexNumber::ComplexNumber()
{
    mRealPart = 0.0;
    mImaginaryPart = 0.0;
}

ComplexNumber::ComplexNumber(double x, double y)
{
    mRealPart = x;
    mImaginaryPart = y;
}

ComplexNumber::ComplexNumber(const ComplexNumber& z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
}

ComplexNumber::ComplexNumber(double real)
{
    mRealPart = real;
    mImaginaryPart = 0.0;
}


double ComplexNumber:: CalculateModulus() const
{
    return sqrt(mRealPart * mRealPart + mImaginaryPart * mImaginaryPart);
}

double ComplexNumber:: CalculateArgument() const
{
    return atan2(mImaginaryPart,mRealPart);
}

ComplexNumber ComplexNumber:: CalculatePower(double n) const
{
    double modulus = CalculateModulus();
    double argument = CalculateArgument();
    double mod_of_result = pow(modulus,n);
    double arg_of_result = argument * n;
    double real_part = mod_of_result * cos(arg_of_result);
    double imag_part = mod_of_result * sin(arg_of_result);
    ComplexNumber z(real_part,imag_part);
    return z;
}

ComplexNumber & ComplexNumber :: operator = (const ComplexNumber & z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
    return *this;
}

ComplexNumber ComplexNumber :: operator- () const
{
    ComplexNumber w;
    w.mRealPart = -mRealPart;
    w.mImaginaryPart = -mImaginaryPart;
    return w;   
}

ComplexNumber ComplexNumber:: operator+(const ComplexNumber&z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart + z.mRealPart;
    w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
    return w;
}

ComplexNumber ComplexNumber:: operator-(const ComplexNumber&z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart - z.mRealPart;
    w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
    return w;
}

std::ostream& operator<<(std::ostream& output,const ComplexNumber& z)
{
    output << "(" << z.mRealPart << " ";
    if (z.mImaginaryPart >= 0.0)
    {
        output << "+ " << z.mImaginaryPart << "i)";
    }
    else
    {
        output << "- " << -z.mImaginaryPart << "i)";
    }
    
    return output;
}

double ComplexNumber:: GetRealPart() const
{
    return mRealPart;
}

double ComplexNumber:: GetImaginaryPart() const
{
    return mImaginaryPart;
}

double RealPart(const ComplexNumber& z)
{
    return z.mRealPart;
}

double ImaginaryPart(const ComplexNumber& z)
{
    return z.mImaginaryPart;
}

ComplexNumber ComplexNumber:: CalculateConjugate() const
{
    return ComplexNumber(mRealPart,-mImaginaryPart);
}

void ComplexNumber:: SetConjugate()
{
    mImaginaryPart = -mImaginaryPart;
}


ComplexNumber ComplexNumber:: operator*(const ComplexNumber&z) const
{
    return ComplexNumber(mRealPart*z.mRealPart -mImaginaryPart*z.mImaginaryPart,
                         mImaginaryPart*z.mRealPart + mRealPart*z.mImaginaryPart);
}
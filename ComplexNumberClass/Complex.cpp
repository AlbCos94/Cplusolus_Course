#include "Complex.hpp"

// we use here as well the name space of the hpp. file
namespace advance_programming
{

// default constructor
Complex::Complex()
    : real(0)
    , imaginary(0)
{
}

Complex::Complex(double real, double imaginary)
    : real(real)
    , imaginary(imaginary)
{
}

// implementation of the copy constructor
Complex::Complex(const Complex& other_object)
{
    std::cout << "Copy constructor running" << std::endl;
    this->real = other_object.real;
    this->imaginary = other_object.imaginary;
}

Complex::~Complex()
{
}

const Complex& Complex::operator=(const Complex& other)
{
    this->real = other.real;
    this->imaginary = other.imaginary;
    return *this; // we return a reference of this object
}

// consider that the namespace is used for the name of the fuuntion implemented
std::ostream& operator<<(std::ostream& out,
    const Complex& complex) // this implementation would be in a cpp file
{
    out << "Complex Num: ( " << complex.real << " ,  " << complex.imaginary << "i )";
    return out;
}
} // end of  namespace advance_programming

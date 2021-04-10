#include "ComplexV2.hpp"

namespace advance_programming
{
// default constructor
ComplexV2::ComplexV2()
    : real(0)
    , imaginary(0)
{
}

// constructor with parameters
ComplexV2::ComplexV2(double real, double imaginary)
    : real(real)
    , imaginary(imaginary)
{
}

// copy constructor
ComplexV2::ComplexV2(const ComplexV2& other_object)
{
    this->real = other_object.real;
    this->imaginary = other_object.imaginary;
}

// destructor
ComplexV2::~ComplexV2()
{
}

// assignment operator overloading
const ComplexV2& ComplexV2::operator=(const ComplexV2& other)
{
    this->real = other.real;
    this->imaginary = other.imaginary;
    return *this;
}

//  FRIEND FUNCTIONS
// Friend function to implement the << operator
std::ostream& operator<<(std::ostream& out, const ComplexV2& complex)
{
    out << "Complex Num: ( " << complex.real << ",  " << complex.imaginary << "i )";
    return out;
}

// Friend function to implement the + operator ( sum complex numbers between them)
ComplexV2 operator+(const ComplexV2& c1, const ComplexV2& c2)
{
    return ComplexV2(
        c1.real + c2.real, c1.imaginary + c2.imaginary); // we return a new object with the sum of the other objects
}
// Friend function to implement the + operator ( sum complex numbers plus double number)
ComplexV2 operator+(const ComplexV2& c1, double d)
{
    return ComplexV2(c1.real + d, c1.imaginary); // we return a new object with the sum of the other objects
}

// Friend function to implement the + operator this time changing the order parameters, to be able to sum "double" +
// object
ComplexV2 operator+(double d, const ComplexV2& c1)
{
    return ComplexV2(c1.real + d, c1.imaginary); // we return a new object with the sum of the other objects
}

// Friend functions to implement the - operator ( substract complex numbers between them)
ComplexV2 operator-(const ComplexV2& c1, const ComplexV2& c2)
{
    return ComplexV2(
        c1.real - c2.real, c1.imaginary - c2.imaginary); // we return a new object with the sum of the other objects
}
ComplexV2 operator-(const ComplexV2& c1, double d)
{
    return ComplexV2(c1.real - d, c1.imaginary); // we return a new object with the sum of the other objects
}
ComplexV2 operator-(double d, const ComplexV2& c1)
{
    return ComplexV2(c1.real - d, c1.imaginary); // we return a new object with the sum of the other objects
}
}
#include "Complex.h"

namespace advance_programming
{
// default constructor
Complex::Complex()
    : real(0)
    , imaginary(0)
{
}

// constructor with parameters
Complex::Complex(double real, double imaginary)
    : real(real)
    , imaginary(imaginary)
{
}

// copy constructor
Complex::Complex(const Complex& other_object)
{
    this->real = other_object.real;
    this->imaginary = other_object.imaginary;
}

// destructor
Complex::~Complex()
{
}

// assignment operator overloading
const Complex& Complex::operator=(const Complex& other)
{
    this->real = other.real;
    this->imaginary = other.imaginary;
    return *this;
}

//  FRIEND FUNCTIONS
// Friend function to implement the << operator
std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    out << "Complex Num: ( " << complex.real << ",  " << complex.imaginary << "i )";
    return out;
}

// Friend function to implement the + operator ( sum complex numbers between them)
Complex operator+(const Complex& c1, const Complex& c2)
{
    return Complex(
        c1.real + c2.real, c1.imaginary + c2.imaginary); // we return a new object with the sum of the other objects
}
// Friend function to implement the + operator ( sum complex numbers plus double number)
Complex operator+(const Complex& c1, double d)
{
    return Complex(c1.real + d, c1.imaginary); // we return a new object with the sum of the other objects
}

// Friend function to implement the + operator this time changing the order parameters, to be able to sum "double" +
// object
Complex operator+(double d, const Complex& c1)
{
    return Complex(c1.real + d, c1.imaginary); // we return a new object with the sum of the other objects
}

// Friend functions to implement the - operator ( substract complex numbers between them)
Complex operator-(const Complex& c1, const Complex& c2)
{
    return Complex(
        c1.real - c2.real, c1.imaginary - c2.imaginary); // we return a new object with the sum of the other objects
}
Complex operator-(const Complex& c1, double d)
{
    return Complex(c1.real - d, c1.imaginary); // we return a new object with the sum of the other objects
}
Complex operator-(double d, const Complex& c1)
{
    return Complex(c1.real - d, c1.imaginary); // we return a new object with the sum of the other objects
}
}
#ifndef COMPLEXV2_HPP
#define COMPLEXV2_HPP

#include <iostream>

namespace advance_programming
{

class ComplexV2
{

private:
    double real;
    double imaginary;

public:
    ComplexV2();                              // default constructor
    ComplexV2(double real, double imaginary); // constructor with parameters
    ComplexV2(const ComplexV2& other_object); // copy constructor

    ~ComplexV2();

    const ComplexV2& operator=(const ComplexV2& other);

    // Implementation of the print opearator "<<"
    friend std::ostream& operator<<(std::ostream& out,
        const ComplexV2& complex); // this implementation would be  in a header file ( with the whole class definition)

    // USE OF THE + OPERATOR IN DIFFERENT CASES

    friend ComplexV2 operator+(const ComplexV2& c1, const ComplexV2& c2);
    friend ComplexV2 operator+(const ComplexV2& c1, double d);
    friend ComplexV2 operator+(double d, const ComplexV2& c1); //

    // USE OF THE - OPERATOR IN DIFFERENT CASES
    friend ComplexV2 operator-(const ComplexV2& c1, const ComplexV2& c2);
    friend ComplexV2 operator-(const ComplexV2& c1, double d);
    friend ComplexV2 operator-(double d, const ComplexV2& c1);

    // IMPLEMENTATION OF THE == OPERATOR
    bool operator==(const ComplexV2& other) const;
    // IMPLEMENTATION OF != OPERATOR
    bool operator!=(const ComplexV2& other) const;

    // IMPLEMENTATION OF THE * OPERATOR (dereference)
    // we will return a new object
    // we can implement it a a method of the same class, since we are just using the implicit object of the class 'this'
    // to create and return a new object out of it
    ComplexV2 operator*() const;
};
}

#endif // COMPLEXV2_HPP

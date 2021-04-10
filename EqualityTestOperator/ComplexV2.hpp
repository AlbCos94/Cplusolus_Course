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
    // since the implicit first argument is already the one of the class itself ('this'), we implement that function as
    // a method of the class
    bool operator==(const ComplexV2& other) const;
    // the last 'const' it is written, since we are not going to change the object that is
    // going to be called  --> the implicit object 'this'

    // IMPLEMENTATION OF != OPERATOR
    bool operator!=(const ComplexV2& other) const;
};
}

#endif // COMPLEXV2_HPP

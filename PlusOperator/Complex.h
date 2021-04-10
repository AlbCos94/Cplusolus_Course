#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

namespace advance_programming
{

class Complex
{

private:
    double real;
    double imaginary;

public:
    Complex();                              // default constructor
    Complex(double real, double imaginary); // constructor with parameters
    Complex(const Complex& other_object);   // copy constructor

    ~Complex();

    const Complex& operator=(const Complex& other);

    // Implementation of the print opearator "<<"
    friend std::ostream& operator<<(std::ostream& out,
        const Complex& complex); // this implementation would be  in a header file ( with the whole class definition)

    // USE OF THE + OPERATOR IN DIFFERENT CASES
    // Implementation of the + operator --> we are creating a NEW object, we dont return a reference (&)
    friend Complex operator+(const Complex& c1,
        const Complex& c2); // the two inputs are constants ( we dont want to change them )
    // we can also use the + with different types, for example double. We have just to change the parameters of the
    // fucntion signature. Of course we have to implement again this function..
    friend Complex operator+(const Complex& c1, double d);
    // THE ORDER MATTERS!!! --> now we create a new signature with a double on the left to be able to sum "double +
    // object", and not only "object"+double" like we defined before
    friend Complex operator+(double d, const Complex& c1); //

    // USE OF THE - OPERATOR IN DIFFERENT CASES
    friend Complex operator-(const Complex& c1, const Complex& c2);
    friend Complex operator-(const Complex& c1, double d);
    friend Complex operator-(double d, const Complex& c1);
    /*
        // Another way to implement the print function. Not doing the function a "friend function" but creating set and
       get
        // method to acces their private elements
        // implemented inline, since it is a really low amount of code
        // the second 'const' is to guarantee that this function will not change anything from that
        // class ( it is mandatory to use this "const" when using function that has a parameter a
        // "const" argument of that object). Then we are assuring that we will not change that parameter
        double getReal const()
        {
            return real;
        }
        double getImaginary const()
        {
            return imaginary;
        }
         *
    */
};

// std::ostream& operator<<(std::ostream& out, const Complex& c); // --> we would define this function outside the class
// in the cpp file, we would write the implementation of the function
}

#endif // COMPLEX_H

#include <cmath>
#include <iostream>
using namespace std;

/**
 *  this class represent complex number and have all the functions that we need to work with complex numbers
*/
class Complex {
   private:
    double real;
    double imaginary;

   public:
    // constructor
    Complex(double re, double im) : real(re), imaginary(im) {}
     
    // copy constructor
    Complex(const Complex &other) : real(other.real), imaginary(other.imaginary) {}

    double get_real() const;

    double get_imaginary() const;
     
    bool operator<(const Complex &other);

    friend ostream &operator<<(ostream &out, const Complex &c);
};

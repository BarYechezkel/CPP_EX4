#include <cmath>
#include <iostream>
using namespace std;

// this class represent complex number and have all the functions that we need to work with complex numbers
class Complex
{
private:
public:
    double real;
    double imaginary;
    // constructor
    Complex(double real, double imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    // copy constructor
    Complex(const Complex &other)
    {
        this->real = other.real;
        this->imaginary = other.imaginary;
    }

    // destructor
    ~Complex()
    {
    }

    // operator overloading
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex &other) const
    {
        return Complex(real * other.real - imaginary * other.imaginary, real * other.imaginary + imaginary * other.real);
    }

    Complex operator+=(const Complex &other)
    {
        real += other.real;
        imaginary += other.imaginary;
        return *this;
    }

    Complex operator-=(const Complex &other)
    {
        real -= other.real;
        imaginary -= other.imaginary;
        return *this;
    }

    Complex operator*=(const Complex &other)
    {
        double temp_real = real;
        real = real * other.real - imaginary * other.imaginary;
        imaginary = temp_real * other.imaginary + imaginary * other.real;
        return *this;
    }

    Complex operator=(const Complex &other)
    {
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    }

    bool operator==(const Complex &other) const
    {
        return (real == other.real && imaginary == other.imaginary);
    }

    bool operator!=(const Complex &other) const
    {
        return !(*this == other);
    }

    bool operator>(const Complex &other) const
    {
        return (real > other.real && imaginary > other.imaginary);
    }

    bool operator<(const Complex &other)
    {
        return sqrt(real * real + imaginary * imaginary) < sqrt(other.real * other.real + other.imaginary * other.imaginary);
    }

    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        out << c.real << " + " << c.imaginary << "i";
        return out;
    }
};

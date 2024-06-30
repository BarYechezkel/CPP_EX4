#include "Complex.hpp"

double Complex::get_real() const {
    return real;
}

double Complex::get_imaginary() const {
    return imaginary;
}

bool Complex::operator<(const Complex& other) {
    return sqrt(real * real + imaginary * imaginary) < sqrt(other.real * other.real + other.imaginary * other.imaginary);
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real << " + " << c.imaginary << "i";
    return out;
}

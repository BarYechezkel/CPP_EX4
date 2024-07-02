#include "Complex.hpp"

double Complex::get_real() const {
    return real;
}

double Complex::get_imaginary() const {
    return imaginary;
}

bool Complex::operator<(const Complex& other) const {
    return sqrt(real * real + imaginary * imaginary) < sqrt(other.real * other.real + other.imaginary * other.imaginary);
}

bool Complex::operator>(const Complex& other) const {
    // if not less than and not equal to, then it is greater than
    return !(*this < other) && !(*this == other);
}

bool Complex::operator==(const Complex& other) const {
    return (this->real == other.real) && (this->imaginary == other.imaginary);
}

bool Complex::operator!=(const Complex& other) const {
    return real != other.get_real() || imaginary != other.get_imaginary();
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real << " + " << c.imaginary << "i";
    return out;
}

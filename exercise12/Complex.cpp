#include <iostream>
#include "Complex.h"

Complex operator+(double r, const Complex &other) {
    double result_real = r + other.real;
    double result_imaginary = other.imag;
    return Complex(result_real, result_imaginary);
}

std::ostream &operator<<(std::ostream &os, const Complex &other) {
    os << other.real << "+" << other.imag << "i";
    return os;
}

Complex::Complex() : real(0), imag(0) {}

Complex::Complex(double re, double im) : real(re), imag(im) {}

Complex::Complex(double re) : real(re), imag(0) {}


Complex Complex::operator+(const Complex &other) const {
    double result_real = real + other.real;
    double result_imaginary = imag + other.imag;
    return Complex(result_real, result_imaginary);
}

Complex Complex::operator+(double real) const {
    double result_real = real + this->real;
    double result_imaginary = imag;
    return Complex(result_real, result_imaginary);
}

Complex Complex::operator-(const Complex &other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator~() const {
    return Complex(real, -imag);
}

Complex Complex::operator*(const Complex &other) const {
    return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
    );
}


Complex operator*(double r, const Complex &other) {
    return Complex(r * other.real, r * other.imag);
}

bool Complex::operator==(const Complex &other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex &other) const {
    return !(operator==(other));
}

void Complex::Show() const {
    std::cout << real << "+" << imag << "i" << std::endl;
}

std::istream &operator>>(std::istream &is, Complex &other) {
    is >> other.real;
    is >> other.imag;
    return is;
}

#ifndef EXAMPLE_COMPLEX1_H
#define EXAMPLE_COMPLEX1_H

#include <iostream>

class Complex {
public:
    Complex();

    Complex(double re, double im);

    Complex(double re);

    void Show() const;

    Complex operator+(const Complex &other) const;

    Complex operator+(double r) const;

    Complex operator-(const Complex &other) const;

    Complex operator~() const;

    Complex operator*(const Complex &other) const;

    bool operator==(const Complex &other) const;

    bool operator!=(const Complex &other) const;

    friend Complex operator+(double r, const Complex &other);

    friend Complex operator*(double r, const Complex &other);

    friend std::ostream &operator<<(std::ostream &os, const Complex &other);

    friend std::istream &operator>>(std::istream &is, Complex &other);

private:
    double imag;
    double real;

};


#endif //EXAMPLE_COMPLEX1_H

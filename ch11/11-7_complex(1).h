// complex.h
#include<iostream>

class Complex{

private:
    double real;
    double virt;

public:

    Complex();
    Complex(double r, double v);

    friend Complex operator+(const Complex & c1, const Complex & c2);
    friend Complex operator-(const Complex & c1, const Complex & c2);
    friend Complex operator*(const Complex & c1, const Complex & c2);
    friend Complex operator*(double d, const Complex & c);

    friend Complex operator~(const Complex & c);

    friend std::ostream & operator<<(std::ostream & os, Complex & c);
    friend std::istream & operator>>(std::istream & is, Complex & c);

};

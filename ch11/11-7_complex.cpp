#include"11-7_complex.h"

Complex::Complex(){
    real = 0.0;
    virt = 0.0;
}

Complex::Complex(double r, double v){
    real = r;
    virt = v;
}

Complex operator+(const Complex & c1, const Complex & c2){
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.virt = c1.virt + c2.virt;
    return sum;
}

Complex operator-(const Complex & c1, const Complex & c2){
    return Complex(c1.real-c2.real, c1.virt-c2.virt);
}

Complex operator*(const Complex & c1, const Complex & c2){
    return Complex(c1.real*c2.real-c1.virt*c2.virt,c1.real*c2.virt-c1.virt*c2.real);
}

Complex operator*(double d, const Complex & c){
    return Complex(d*c.real, d*c.virt);
}

Complex operator~(const Complex & c){
    return Complex(c.real, -c.virt);
}

std::ostream & operator<<(std::ostream & os, const Complex & c){
    os << "(" << c.real << ", " << c.virt <<  ")";
    return os;
}

std::istream & operator>>(std::istream & is, Complex & c){
    is >> c.real >> c.virt;
    return is;
}
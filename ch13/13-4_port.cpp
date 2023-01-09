#include"13-4_port.h"
#include<cstring>

Port::Port(const char * br, const char * st, int b){
    brand = new char[strlen(br)+1];
    strcpy(brand,br);
    strncpy(style,st,19);
    style[19]='\0';
    bottles = b;
}

Port::Port(const Port & p){
    brand = new char[strlen(p.brand)+1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p){
    if(this==&p){
        return *this;
    }
    delete[] brand;
    brand = new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles = p.bottles;
    return *this;
}


Port & Port::operator+=(int b){
    if(bottles+b>=0){
        bottles+=b;
    }
    return *this;
}


Port & Port::operator-=(int b){
    if(bottles-b>=0){
        bottles-=b;
    }
    return *this;
}


void Port::show() const{
    std::cout << "brand: " << brand << std::endl;
    std::cout << "style: " << style << std::endl;
    std::cout << "bottles: " << bottles << std::endl;
}

ostream & operator<<(ostream & os, const Port & p){
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}
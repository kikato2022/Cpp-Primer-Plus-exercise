#include"13-3_dma.h"
#include "13-3_abc.h"

#include<cstring>


// baseDMA
baseDMA::baseDMA(const char * l, int r) : AbcDMA(l,r){
    //std::cout << "baseDMA consturcted" << std::endl;
    //std::cout << l << ", " << r << std::endl;
}

baseDMA::baseDMA(const baseDMA & rs) : AbcDMA(rs){

}

baseDMA & baseDMA::operator=(const baseDMA & rs){
    AbcDMA::operator=(rs);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs){
    std::cout << "baseDMA view" << std::endl;
    os << (const AbcDMA &) rs;
    return os;
}

void baseDMA::view(){
    AbcDMA::view();
}


// lacksDMA
lacksDMA::lacksDMA(const char * c, const char * l, int r )
    : AbcDMA(l, r)
{
    strncpy(color, c, COL_LEN-1);
    color[COL_LEN-1] = '\0';
}

lacksDMA::lacksDMA(const char * c, const AbcDMA & abc)
    : AbcDMA(abc)
{
    strncpy(color, c, COL_LEN-1);
    color[COL_LEN-1] = '\0';
}

lacksDMA::lacksDMA(const lacksDMA & la)
    : AbcDMA(la)
{
    strcpy(color, la.color);
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & la){
    std::cout << "lacksDMA view" << std::endl;
    os << (const AbcDMA &) la << ", color: " << la.color;
    return os;
}

void lacksDMA::view(){
    AbcDMA::view();
    std::cout << ", color: " << color;
}


// hasDMA
hasDMA::hasDMA(const char * s , const char * l , int r)
    : AbcDMA(l,r)
{
    style = new char[strlen(s)+1];
    strcpy(style,s);
}


hasDMA::hasDMA(const char * s, const AbcDMA & abc)
    : AbcDMA(abc)
{
    style = new char[strlen(s)+1];
    strcpy(style,s);
}

hasDMA::hasDMA(const hasDMA & hs)
    : AbcDMA(hs)
{
    style = new char[strlen(hs.style)+1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA(){
    delete [] style;
}


hasDMA & hasDMA::operator=(const hasDMA & hs){
    if(this==&hs){
        return *this;
    }
    AbcDMA::operator=(hs);
    delete[] style;
    style = new char[strlen(hs.style)+1];
    strcpy(style, hs.style);
    return *this;
}


std::ostream & operator<<(std::ostream & os, const hasDMA & hs){
    std::cout << "hasDMA view" << std::endl;
    os << (const AbcDMA &) hs << ", style: " << hs.style;
    return os;
}

void hasDMA::view(){
    AbcDMA::view();
    std::cout << ", style: " << style;
}
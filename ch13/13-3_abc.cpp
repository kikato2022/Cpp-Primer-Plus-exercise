#include"13-3_abc.h"
#include<cstring>


AbcDMA::AbcDMA(const char * l, int r){
    //std::cout << "AbcDMA constructed" << std::endl;
    //std::cout << "label: " << l << ", rating: " << r << std::endl;
    label = new char[strlen(l)+1];
    strcpy(label,l);
    rating = r;
}

AbcDMA::AbcDMA(const AbcDMA & abc){
    label = new char[strlen(abc.label)+1];
    strcpy(label, abc.label);
    rating = abc.rating;
}

AbcDMA::~AbcDMA(){
    delete [] label;
}

AbcDMA & AbcDMA::operator=(const AbcDMA & abc){
    if(this == &abc){
        return *this;
    }
    delete[]label;
    label = new char[strlen(abc.label)+1];
    strcpy(label,abc.label);
    rating = abc.rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const AbcDMA & abc){
    //std::cout << "abcDMA view" << std::endl;
    os << "label: " << abc.label << ", rating: " << abc.rating;
    return os;
}

void AbcDMA::view(){
    std::cout << "label: " << label << ", rating: " << rating;
}


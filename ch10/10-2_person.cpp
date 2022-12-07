#include"10-2_person.h"
#include<iostream>
#include<cstring>

Person::Person(const std::string & ln, const char * fn){
    lname = ln;
    strcpy(fname,fn);
}

void Person::show() const{
    std::cout <<"Name is: " << fname << ' ' << lname << '\n';
    
}

void Person::FormalShow() const{
    std::cout <<"Name is: " << lname << ", " << fname << '\n';
}
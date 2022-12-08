#include"10-7_plorg.h"
#include<iostream>
#include<cstring>

Plorg::Plorg(const char * sname, int ci){
    strcpy(name,sname);
    CI = ci;
}

void Plorg::show() const{
    std::cout << "name is " << name;
    std::cout << ", CI is " << CI << std::endl;
}
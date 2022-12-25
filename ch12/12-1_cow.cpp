#include "12-1_cow.h"
#include<cstring>
#include<iostream>


Cow::Cow(){
    name[0] = '\0';
    hobby = nullptr;
    weight = 0.0;
}


Cow::Cow(const char * nm, const char * ho, double wt){
    std::strcpy(name,nm);
    hobby = new char[strlen(ho)+1];
    std::strcpy(hobby, ho);
    weight = wt;
}


Cow::Cow(const Cow & c){
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight = c.weight;
}


Cow::~Cow(){
    delete [] hobby;
}


Cow & Cow::operator=(const Cow & c){
    if(this==&c){
        return *this;
    }
    strcpy(name,c.name);
    delete [] hobby;
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight = c.weight;
    return *this;
}


void Cow::ShowCow() const {
    std::cout << "name: " << name << std::endl;
    std::cout << "  hobby: " << hobby << std::endl;
    std::cout << "  weight: " << weight << std::endl;
}
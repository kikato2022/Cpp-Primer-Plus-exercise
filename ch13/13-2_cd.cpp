#include"13-2_cd.h"

#include<cstring>
#include<iostream>

// base class
Cd::Cd(const char * s1, const char * s2, int n, double x){
    performers = new char[strlen(s1)+1];
    std::strcpy(performers, s1);

    label = new char[strlen(s2)+1];
    std::strcpy(label, s2);  
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d){
    performers = new char[strlen(d.performers)+1];
    std::strcpy(performers, d.performers);
    label = new char[strlen(d.label)+1];
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd(){
    performers = nullptr;
    label = nullptr;
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd(){
    delete [] performers;
    delete [] label;
}

void Cd::Report() const{   // reports all CD data
    using std::cout;
    using std::endl;
    cout << "performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "selections: " << selections << endl;
    cout << "playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d){
    if(this == &d){
        return *this;
    }

    delete [] performers;
    performers = new char[strlen(d.performers)+1];
    std::strcpy(performers,d.performers);
    delete [] label;
    label = new char[strlen(d.label)+1];
    std::strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}


// derived class
Classic::Classic(const char * w, const char * s1, const char *s2, int n, double x)
    : Cd(s1,s2,n,x)
{
    works = new char[strlen(w)+1];
    strcpy(works, w);
}

Classic::Classic(const Classic & cla)
    : Cd(cla)
{
    works = new char[strlen(cla.works) + 1];
    strcpy(works, cla.works);
}

Classic::Classic():Cd(){
    works = nullptr;
}

Classic::~Classic(){
    delete [] works;
}


void Classic::Report() const{
    std::cout<< "works: " << works << std::endl;
    Cd::Report();
}

Classic & Classic::operator=(const Classic & cla){
    if(this == &cla){
        return *this;
    }

    Cd::operator=(cla);

    delete [] works;
    works = new char[strlen(cla.works) + 1];
    strcpy(works, cla.works);

    return *this;
}
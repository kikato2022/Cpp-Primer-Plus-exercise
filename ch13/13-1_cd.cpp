#include"13-1_cd.h"

#include<cstring>
#include<iostream>

// base class
Cd::Cd(const char * s1, const char * s2, int n, double x){
    std::strncpy(performers, s1, 49);
    performers[49]='\0';
    std::strncpy(label, s2, 19);
    performers[19] = '\0';
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d){
    std::strncpy(performers,d.performers,49);
    performers[49] = '\0';
    std::strncpy(label,d.label,19);
    label[19] = '\0';
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd(){
    performers[0]='\0';
    label[0]='\0';
    selections = 0;
    playtime = 0.0;
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
    if(this== &d){
        return *this;
    }

    std::strcpy(performers,d.performers);
    std::strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}


// derived class
Classic::Classic(const char * w, const char * s1, const char *s2, int n, double x)
    : Cd(s1,s2,n,x)
{
    strncpy(works, w, 49);
    works[49] = '\0';
}

Classic::Classic(const Classic & cla)
    : Cd(cla)
{
    strcpy(works, cla.works);
}

Classic::Classic():Cd(){
    works[0] = '\0';
}


void Classic::Report() const{
    std::cout<< "works: " << works << std::endl;
    Cd::Report();
}

Classic & Classic::operator=(const Classic & cla){
    Cd::operator=(cla);
    strcpy(works, cla.works);
    return *this;
}
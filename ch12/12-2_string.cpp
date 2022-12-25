#include"12-2_string.h"
#include<cstring>
#include<cctype>

int String::num_strings = 0;

String::String(const char * s){
    len = strlen(s);
    str = new char[len+1];
    strcpy(str, s);
    num_strings++;
}

String::String(){
    len = 0;
    str = nullptr;
    num_strings++;
}

String::String(const String & s){
    len = s.len;
    str = new char[len+1];
    strcpy(str,s.str);
    num_strings++;
}

String::~String(){
    num_strings--;
    delete [] str;
}

void String::Stringlow(){
    for(int i = 0; i<len; i++){
        str[i] = tolower(str[i]);
    }
}

void String::Stringup(){
    for(int i = 0; i<len; i++){
        str[i] = toupper(str[i]);
    }
}

int String::count(const char & a) const{
    int total = 0;
    for(int i=0; i<len; i++){
        if(str[i]==a) total++;
    }
    return total;
}

String & String::operator=(const String & s){
    if(this == &s) 
        return *this;
    len = s.len;
    delete [] str;
    str = new char[len+1];
    strcpy(str,s.str);
    return *this;
}

String & String::operator=(const char * s){
    len = strlen(s);
    delete [] str;
    str = new char[len+1];
    strcpy(str,s);
    return *this;
}


char & String::operator[] (int i){
    return str[i];
}


const char & String::operator[] (int i) const{
    return str[i];
}


bool operator<(const String & st1, const String & st2){
    return (strcmp(st1.str, st2.str)<0);
}

bool operator>(const String & st1, const String & st2){
    return (strcmp(st1.str, st2.str)>0);
}


bool operator==(const String & st1, const String & st2){
    return (strcmp(st1.str, st2.str)==0);
}

ostream & operator<<(ostream & os, const String & st){
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String & st){

    char temp[String::CINLIM];
    is.get(temp,String::CINLIM);

    if(is)
        st = temp;

    while(is&&is.get()!='\n') continue;

    return is;
}


String operator+(const String & st1, const String & st2){
    String temp;
    temp.len = st1.len + st2.len;
    char ctemp[temp.len+1];
    strcpy(ctemp,st1.str);
    strcat(ctemp,st2.str);
    temp = ctemp;
    return temp;
}

int String::HowMany(){
    return num_strings;
}
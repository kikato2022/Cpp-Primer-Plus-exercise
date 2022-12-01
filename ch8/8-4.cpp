#include<iostream>
using namespace std;
#include<cstring> // for strlen(), strcpy()


struct stringy {
    char * str;
    int ct;
};

void set(stringy &, char *);
void show(const stringy &, int = 1);
void show(const char *, int = 1);


int main(){
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany,2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing,3);
    show("Done!");
    return 0;






}

void set(stringy & sgy, char * s){
    int len = strlen(s);
    sgy.str = new char[len+1];
    strcpy(sgy.str, s);
    sgy.ct = len;
}

void show(const stringy & sgy, int num){
    for(int i=0;i<num;i++){
        cout << sgy.str << endl;
    }
}

void show(const char * s, int num){
    for(int i=0; i<num; i++){
        cout << s << endl;
    }
}
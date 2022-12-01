#include<iostream>
#include<cstring>
using namespace std;

struct CandyBar{
    char name[20];
    double weight;
    int carluli;
};

void set_CandyBar(CandyBar &, const char * = "Millennium Munch", double =  2.85, int = 350);

void show_CandyBar(const CandyBar &);

int main(){
    CandyBar candy;
    set_CandyBar(candy);
    show_CandyBar(candy);
    return 0;
}

void set_CandyBar(CandyBar & cb, const char * name, double weight, int carluli){
    strcpy(cb.name, name);
    cb.weight = weight;
    cb.carluli = carluli;
}

void show_CandyBar(const CandyBar & cb){
    cout << "Candy Bar's name: " << cb.name << endl;
    cout << "Weight is " << cb.weight << " Carluli is " << cb.carluli << endl;
}
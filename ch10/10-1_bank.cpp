#include"10-1_bankcount.h"
#include<iostream>

int main(){
    
    Bankcount b;
    b.show();
    b.deposit(10);
    b.show();
    b.fetch(5);
    b.fetch(10);
    b.show();
    b.deposit(100000);
    b.show();
    b.fetch(1000);
    b.show();

    return 0;
}
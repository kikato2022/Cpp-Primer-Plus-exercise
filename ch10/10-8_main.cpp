#include "10-8_list.h"
#include<iostream>

void show(Item & item){
    std::cout << "Item is " << item << std::endl;
}

int main(){

    using std::cout;
    using std::endl;

    List l;
    cout << l.isempty() << endl;
    Item it = 11;
    
    l.visit(show);

    cout << l.isempty() << endl;

    for(int i=0;i<5;i++){
        l.add(i);
    }

    l.visit(show);

    return 0;
}
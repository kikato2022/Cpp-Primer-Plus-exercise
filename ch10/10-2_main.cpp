#include"10-2_person.h"

int main(){
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.show();
    one.FormalShow();
    two.show();
    two.FormalShow();
    three.show();
    three.FormalShow();

    return 0;
}
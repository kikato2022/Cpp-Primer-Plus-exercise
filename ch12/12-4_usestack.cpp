#include"12-4_stack.h"
#include<iostream>

int main(){

    Stack a(10);
    a.push(10);
    a.push(12);
    Stack b;
    Stack c(a);
    c.push(100);
    c.push(200);
    Item temp;
    c.pop(temp);
    std::cout << temp << std::endl;
    c.pop(temp);
    std::cout << temp << std::endl;
    c.pop(temp);
    std::cout << temp << std::endl;
    c.pop(temp);
    std::cout << temp << std::endl;
    return 0;
}
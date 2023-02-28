#include<iostream>

int main() {
    int ct = 0;
    while(std::cin.peek()!='$'){
        ct++;
        std::cin.get();
    }
    std::cout << "num: " << ct << std::endl;

    return 0;
}
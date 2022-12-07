#include "10-3_golf.h"

#include<iostream>
#include<cstring>


Golf::Golf(const char * name, int hc){
    strcpy(fullname, name);
    handicap = hc;
}

void Golf::set_handicap(int hc){
    handicap = hc;
}

void Golf::show() const{
    std::cout << "Player name is " << fullname
              << ", player handicap is " << handicap << '\n';
}

// interactive version:
//  function solicits name and handicap from user
//  and sets the members of g to the values entered
//  returns 1 if name is entered, 0 if name is empty string
int setgolf(Golf & g){

    std::cout << "Input the player name: ";
    char playername[40];
    std::cin.getline(playername,40);
    if(std::cin.fail()){
        std::cin.clear();
        while(std::cin.get()!='\n') continue;
    }

    if(strlen(playername)==0){
        std::cout << "You have entered an empty string.\n";
        return 0;
    }
    else{
        std::cout << "Input the player handicap: ";
        int hc;
        std::cin >> hc;
        g = Golf(playername,hc);
        return 1;
    }
}
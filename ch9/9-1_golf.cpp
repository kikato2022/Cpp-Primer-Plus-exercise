#include <iostream>
#include "9-1_golf.h"
#include <cstring>


// non-interactive version:
//  function sets golf structure to provided name, handicap
//  using values passed as arguments to the function
void setgolf(golf & g, const char * name, int hc){
    strcpy(g.fullname, name);
    g.handicap = hc;
}

// interactive version:
//  function solicits name hand handicap from user
//  and sets the members of g to the values entered
//  returns 1 if name is entered, 0 if name is empty string
int setgolf(golf & g){

    char str[Len];
    int hc;
    std::cout << "Input name: ";
    std::cin.getline(str, Len);

    if(strlen(str)!=0){
        std::cout << "Input handicap: ";
        std::cin >> hc;
        while(std::cin.get()!='\n') continue;
        setgolf(g,str,hc);
        return 1;
    }
    else{
        return 0;
    } 
}

// function resets handicap to new value
void handicap(golf & g, int hc){
    g.handicap = hc;
}

// function displays contents of golf structure
void showgolf(const golf & g){
    std::cout << "Name: " << g.fullname;
    std::cout << ", handicap: " << g.handicap << std::endl;
}
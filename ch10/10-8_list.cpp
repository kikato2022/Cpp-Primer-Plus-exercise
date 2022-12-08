#include"10-8_list.h"
#include<iostream>

List::List(){
    tail = 0;
}

void List::add(const Item &item){
    if(tail<MAX){
        list[tail++] = item;
    }
    else{
        std::cout << "List is full, add failed." << std::endl;
    }
}

bool List::isempty() const{
    if(tail==0)
        return true;
    else
        return false;
}

bool List::isfull() const{
    if(tail==MAX)
        return true;
    else
        return false;
}

void List::set(const Item & item){
    for(int i=0;i<tail;i++){
        list[i] = item;
    }
}

void List::add_op(const Item &item){
    for(int i=0;i<tail;i++){
        list[i] += item;
    }
}

void List::minus_op(const Item &item){
    for(int i=0;i<tail;i++){
        list[i] -= item;
    }
}

void List::visit(void (*pf)(Item & item)){
    for(int i=0;i<tail;i++){
        (*pf)(list[i]);
    }
}

void List::show() const{
    for(int i=0; i<tail; i++){
        std::cout << list[i] << ' ';
    }
    std::cout << '\n';
}
#include"10-5_customer.h"
#include<iostream>


Customer_Stack::Customer_Stack(){
    top = 0;
    total = 0.0;
}


bool Customer_Stack::isempty() const {

    if(top==0) return true;
    else return false;

}


bool Customer_Stack::isfull() const {

    if(top+1==MAX) return true;
    else return false;

}


bool Customer_Stack::push(const Customer & customer) {

    if( top == MAX ) {
        std::cout << "Stack is full, push failed." << std::endl;
        return false;
    }
    else{
        stack[top++] = customer;
        return true;
    }

}


bool Customer_Stack::pop(Customer & customer){      // pop into item

    if(top==0){
        std::cout << "Stack is empty, pop failed." << std::endl;
        return false;
    }
    else{
        customer = stack[--top];
        total += customer.payment;
        std::cout << "Total income is " << total << std::endl;
        return true;
    }

}
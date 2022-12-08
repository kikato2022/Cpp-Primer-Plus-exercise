#include"10-5_customer.h"

int main(){
    
    Customer_Stack stack;
    Customer one = {"aaa", 12};
    stack.push(one);
    Customer two = {"two", 15};
    stack.push(two);
    Customer three = {"three", 16};
    stack.push(three);
    Customer four = {"four", 18};
    Customer pool;

    for(int i=0; i<8; i++){
        stack.pop(pool);
    }

    return 0;   
}
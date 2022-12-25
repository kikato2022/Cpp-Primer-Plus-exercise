#include"12-4_stack.h"

Stack::Stack(int n){
    size = n;
    pitems = new Item[size];
    top = 0;
}

Stack::Stack(const Stack & st){
    size = st.size;
    pitems = new Item[size];
    for(int i=0;i<size; i++){
        pitems[i] = st.pitems[i];
    }
    top = st.top;
}

Stack::~Stack(){
    delete [] pitems;
}

bool Stack::isempty() const {
    return top==0;
}

bool Stack::isfull() const {
    return top==size;
}

bool Stack::push(const Item &item){
    if(top==size) return false;
    else{
        pitems[top++] = item;
        return true;
    }
}

bool Stack::pop(Item & item){
    if(top==0) return false;
    else {
        item = pitems[--top];
        return true;
    }
}

Stack & Stack::operator=(const Stack & st){

    if(this == &st) 
        return *this;
    size = st.size;
    delete[] pitems;
    pitems = new Item[size];

    for(int i=0;i<size;i++){
        pitems[i] = st.pitems[i];
    }
    top = st.top;
    return *this;
}

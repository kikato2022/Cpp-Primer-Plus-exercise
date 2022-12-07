#include"10-3_golf.h"

const int NUM = 5;
Golf man[NUM];

int main(){
    int i;
    for(i=0; i<NUM; i++){
        if(!setgolf(man[i])) break;
    }

    for(int j=0; j<i; j++){
        man[j].show();
    }
    return 0;
}
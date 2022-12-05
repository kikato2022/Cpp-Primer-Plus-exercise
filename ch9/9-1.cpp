#include"9-1_golf.h"

int main(){
    golf arr[10];
    int i;
    for(i=0;i<10;i++){
        if(!setgolf(arr[i]))
            break;
    }
    for(int j=0;j<i;j++)
        showgolf(arr[j]);
    
}
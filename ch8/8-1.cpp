#include<iostream>
using namespace std;

static int times = 0;

void show(const char *, int = 0);

int main(){

    char morning[50] = "morning girls, jump, jump, jump";
    show(morning);
    cout << "--------------------" << endl;
    show(morning,5);
    cout << "--------------------" << endl;
    show(morning);
    cout << "--------------------" << endl;
    show(morning,10);
    cout << "--------------------" << endl;

    return 0;

}

void show(const char * str, int num){
    times++;
    if(num==0){
        cout << str << endl;
        return;
    }
    else{
        for(int i=0;i<times;i++){
            cout << str << endl;
        }
    }
}


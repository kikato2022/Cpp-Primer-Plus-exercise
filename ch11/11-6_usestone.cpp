#include"11-6_stonewt.h"
#include<iostream>

int main(){

    using std::cout;
    using std::endl;
    using std::cin;


    Stonewt st[6] = {
        100,80,60
    };

    int choice;
    int stone;
    double lp;
    double p;

    for(int i=3; i<6; i++){
    
        cout << "input 1 to input stone and left pounds of stonewt,"
        << " or 2 to input pounds of stonewt: ";
        cin >> choice;

        if(choice==1){
            cin >> stone >> lp;
            st[i]= Stonewt(stone, lp);
        }
        else if(choice==2){
            cin >> p;
            st[i] = Stonewt(p);
        }

    }

    Stonewt s(11,0);
    int num = st[0]>s?1:0;
    Stonewt max = st[0];
    Stonewt min = st[0];

    for(int i=0; i<6; i++){
        st[i].show_stn();
    }

    for(int i=1; i<6; i++){
        if(max<st[i]) max = st[i];
        if(min>st[i]) min = st[i];
        if(st[i]>s) num++;
    }

    cout << "Max Stonewt is ";
    max.show_stn();
    cout << endl;

    cout << "Min Stonewt is ";
    min.show_lbs();
    cout << endl;

    cout << "The num of Stonewt bigger than 11 stone is " << num << endl;

    return 0;

}
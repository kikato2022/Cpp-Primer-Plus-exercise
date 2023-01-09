#include "13-3_abc.h"
#include"13-3_dma.h"

#include<iostream>
#include<cstring>

const int NUM = 4;

int main(){
    using std::cin;
    using std::cout;
    using std::endl;

    baseDMA b;
    cout << b << endl;

    AbcDMA * p_dma[NUM];
    char temp[100];
    int tempnum;
    char kind;

    for (int i=0; i<NUM; i++){
        cout << "Enter dma's label: ";
        cin.getline(temp,100);
        cout << "Enter dma's rating: ";
        cin >> tempnum;
        cout << "Enter 1 for baseDMA, 2 for lacksDMA or 3 for hasDMA: ";
        while(cin>>kind && (kind!='1'&&kind!='2'&&kind!='3')){
            cout << "Enter 1, 2, or 3: ";
        }
        if(kind == '1'){
            p_dma[i] = new baseDMA(temp,tempnum);
        }
        else if(kind == '2'){
            char tempcolor[100];
            cout << "Enter the color of lacksDMA: ";
            cin >> tempcolor;
            p_dma[i] = new lacksDMA(tempcolor, temp,tempnum);
        }
        else{
            char tempstyle[100];
            cout << "Enter the style of hasDMA: ";
            cin >> tempstyle;
            p_dma[i] = new hasDMA(tempstyle, temp, tempnum);
        }
        while (cin.get() != '\n'){
            continue;
        }
    }
    cout << endl;
    for(int i = 0; i < NUM; i++ ){
        p_dma[i]->view();
        cout << endl;
    }

    for(int i = 0; i < NUM; i++ ){
        delete p_dma[i];
    }

    cout << "Done.\n";
    return 0;
}
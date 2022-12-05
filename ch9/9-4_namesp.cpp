#include"9-4_namesp.h"
#include<iostream>

namespace SALES {

    // copies the lesser of 4 or n items from the array ar
    // to the sales member of s and computes and stores the 
    // average, maximum, and minimum values of the entered items;
    // remaining elements of sales, if any, set to 0
    void setSales(Sales & s, const double ar[], int n){

        int m = n < QUARTERS? n:QUARTERS;
        for(int i=0; i<m; i++){
            s.sales[i] = ar[i];
        }
        for(int i = m; i < QUARTERS; i++){
            s.sales[i] = ar[i];
        }
        s.max = s.sales[0];
        s.min = s.sales[0];
        double total = s.sales[0];
        for(int i=1; i<m; i++){
            if(s.max<s.sales[i]) s.max = s.sales[i];
            if(s.min>s.sales[i]) s.min = s.sales[i];
            total += s.sales[i];
        }
        s.average = total/m;
    }


    // gathers sales for 4 quarters interactively, stores them
    // in the sales member of s and computes and stores the
    // average, maximum, and minimum values
    void setSales(Sales & s){

        using std::cout;
        using std::cin;
        using std::endl;

        int i;
        for(i=0;i<QUARTERS;i++){
            cout << "Input QUARTER #" << i+1 << " sales";
            cout << "(q to end input): ";
            if(!(cin>>s.sales[i])) break;
        }
        for(int j=i;j<QUARTERS;j++){
            s.sales[j] = 0;
        }
        s.max = s.sales[0];
        s.min = s.sales[0];
        double total = 0;
        for(int j=0; j<i; j++){
            if(s.max<s.sales[j]) s.max = s.sales[j];
            if(s.min>s.sales[j]) s.min = s.sales[j];
            total += s.sales[j];
        }
        s.average = total/i;
    }

    // display all information in structure s
    void showSales(const Sales & s){
        for(int i=0; i<QUARTERS; i++){
            std::cout << "QUARTER #"<<i+1<<" sales " << s.sales[i] << std::endl;
        }
        std::cout<<"Maximum Sale is " << s.max << std::endl;
        std::cout<<"Minimum Sale is " << s.min << std::endl;
        std::cout<<"Average Sale is " << s.average << std::endl;
    }
}
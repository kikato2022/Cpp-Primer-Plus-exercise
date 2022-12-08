#include"10-4_sales.h"
#include<iostream>
using namespace SALES;


Sales::Sales(){
    using std::cout;
    using std::cin;
    using std::endl;

    int i;
    for(i=0;i<QUARTERS;i++){
        cout << "Input the sale of QUARTERS #" << i+1 << "(q to end input):";
        if(!(cin>>sales[i])){
            break;
        }
    }
    
    int Len = i;
    for(i=Len;i<QUARTERS;i++){
        sales[i] = 0.0;
    }

    max = sales[0];
    min = sales[0];
    double total = sales[0];
    for(i=1; i<Len && (sales[i]!=0); i++){

        if( max<sales[i] ) max = sales[i];
        if( min>sales[i] ) min = sales[i];
        total += sales[i];
    }

    average = total / Len;

}

Sales::Sales(const double ar[], int n){
    int len = n < QUARTERS? n : QUARTERS;
    for(int i=0; i<len; i++){
        sales[i] = ar[i];
    }
    for (int i=len; i<QUARTERS;i++){
        sales[i] = 0.0;
    }
    max = sales[0];
    min = sales[0];
    double total = sales[0];
    int i;
    for(i=1; i<len&&(sales[i]!=0);i++){
        if(max<sales[i]) max = sales[i];
        if(min>sales[i]) min = sales[i];
        total += sales[i];
    }
    average = total / i;
}

void Sales::show() const{

    for(int i=0;i<QUARTERS;i++){
        std::cout << "Sale of QUARTERS #" << i+1 <<": " << sales[i] << std::endl;
    }
    std::cout << "Maximum Sale: " << max << std::endl;
    std::cout << "Minimum Sale: " << min << std::endl;
    std::cout << "Average Sale: " << average << std::endl;

}
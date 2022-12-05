#include"9-4_namesp.h"

int main(){
    using namespace SALES;
    Sales a;
    Sales b;
    setSales(a);
    int i;
    for(i=0;i<QUARTERS; i++){
        if(a.sales[i]==0) break;
    }
    setSales(b,a.sales,i);
    showSales(a);
    showSales(b);
}
#include"10-4_sales.h"

int main(){

    using namespace SALES;

    Sales one;

    Sales two(one.sale_arr(),QUARTERS);

    one.show();

    two.show();

}
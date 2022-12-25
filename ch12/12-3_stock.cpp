#include"12-3_stock.h"
#include<cstring>

Stock::Stock(){
    company = nullptr;
    shares = 0;
    share_val = 0.0;
    set_tot();
}

Stock::Stock(const char *co, long n, double pr){
    company = new char[strlen(co)+1];
    strcpy(company, co);
    shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock(){}

void Stock::buy(long num, double price) {
    shares += num;
    share_val = price;
    set_tot();
}

void Stock::sell(long num, double price){
    num = num > shares?shares:num;
    shares-=num;
    share_val = price;
    set_tot();
}

void Stock::update(double price){
    share_val = price;
    set_tot();
}

const Stock & Stock::topval(const Stock & s) const{
    if(s.total_val>total_val) return s;
    else return *this;
}


ostream & operator<<(ostream & os, const Stock & s){
    os << "company: " << s.company << std::endl;
    os << "  shares: " << s.shares << std::endl;
    os.precision(2);
    os << "  total value: $" << s.total_val << std::endl;
    return os;
}
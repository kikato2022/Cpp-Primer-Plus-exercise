#include "10-1_bankcount.h"
#include<iostream>

Bankcount::Bankcount(){
    std::cout << "A new bank count!\n";
    m_name = "no user name";
    m_count = "count is empty";
    m_savings = 0.0;
}

Bankcount::Bankcount(const std::string & name, std::string & count, double savings){
    std::cout << "A new bank count!\n";
    m_name = name;
    m_count = count;
    m_savings = savings;
}

void Bankcount::show() const{
    using std::cout;
    cout << "User name: " << m_name << '\n';
    cout << " count: " << m_count << ", savings: $" << m_savings << '\n';
}

bool Bankcount::deposit(double money){
    using std::cout;
    if(money<0){
        cout << "You can't deposit a negative amount of money.\n";
        return false;
    }
    else if(money==0){
        cout << "Money is zero, there is no need to operate.\n";
        return false;
    }
    else{
        cout << "Deposit $" << money << '\n';
        m_savings += money;
        return true;
    }
}


bool Bankcount::fetch(double money){
    using std::cout;
    if(money<0){
        cout << "You can't fetch a negative amount of money.\n";
        return false;
    }
    else if(money==0){
        cout << "Money is zero, there is no need to operate.\n";
        return false;
    }
    else if(money>m_savings){
        cout << "You can't fetch the amount of money more than you have saved\n";
        return false;
    }
    else{
        cout << "Fetch $" << money << '\n';
        m_savings -= money;
        return true;
    }

}
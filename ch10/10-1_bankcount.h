// bankcount.h
#include<string>

class Bankcount{
private:
    std::string m_name;
    std::string m_count;
    double m_savings;
public:
    Bankcount();
    Bankcount(const std::string & name, std::string & count, double savings = 0.0);
    void show() const;
    bool deposit(double money);
    bool fetch(double money);
};
#include"13-4_vintagePort.h"
#include<cstring>

VintagePort::VintagePort():Port(){
    nickname = nullptr;
    year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
    : Port(br,"none",b)
{
    nickname = new char[strlen(nn)+1];
    strcpy(nickname,nn);
    year = y;
}

VintagePort& VintagePort::operator=(const VintagePort &vp){
    if(this==&vp){
        return *this;
    }

    Port::operator=(vp);
    delete[] nickname;
    nickname = new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::show() const{

    Port::show();
    std::cout<<"nickname: " << nickname << std::endl;
    std::cout<<"year: " << year << std::endl;
}


ostream & operator<<(ostream & os, const VintagePort & vp){
    os << (const Port &) vp << ", " << vp.nickname << ", " << vp.year;
    return os;
}
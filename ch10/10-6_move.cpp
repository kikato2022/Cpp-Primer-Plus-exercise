#include "10-6_move.h"
#include<iostream>


Move::Move(double a, double b){
    x = a;
    y = b;
}


void Move::showmove() const {
    std::cout << "x is " << x << ", y is " << y << std::endl;
}


Move Move::add(const Move & m) const{

    double m_x = x+m.x;
    double m_y = y+m.y;

    return Move(m_x, m_y);

}


void Move::reset(double a, double b){
    x = a;
    y = b;
}
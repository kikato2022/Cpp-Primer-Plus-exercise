// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_

#include<iostream>

class Stonewt{

private:
    enum {Lbs_per_stn = 14};
    enum Status {STONE, INT_POUNDS, FLOAT_POUNDS};
    Status st;

    int stone;
    double left_pds;

    int i_pounds;
    double f_pounds;

    void set_stone();
    void set_i_p();
    void set_f_p();

public:
    Stonewt(double lbs, Status sta = FLOAT_POUNDS);
    Stonewt(int stn, double lbs, Status sta = STONE);
    Stonewt();
    ~Stonewt();

    friend std::ostream & operator<<(std::ostream & os, const Stonewt & stonewt);
    friend Stonewt operator+(Stonewt & s1, Stonewt & s2);
    friend Stonewt operator-(Stonewt & s1, Stonewt & s2);
    friend Stonewt operator*(double d, Stonewt & s);
    friend Stonewt operator*(Stonewt & s, double d);

};



#endif
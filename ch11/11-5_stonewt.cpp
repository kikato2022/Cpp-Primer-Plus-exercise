#include"11-5_stonewt.h"


void Stonewt::set_stone(){
    stone = (int)f_pounds / Lbs_per_stn;
    left_pds = (int)f_pounds % Lbs_per_stn + f_pounds - (int)f_pounds;
}

void Stonewt::set_i_p(){
    i_pounds = (int) f_pounds;
}

void Stonewt::set_f_p(){
    f_pounds = stone * Lbs_per_stn + left_pds;
}

Stonewt::Stonewt(double lbs, Status sta){
    if(sta == FLOAT_POUNDS){
        st = sta;
        f_pounds = lbs;
        set_i_p();
        set_stone();
    }
    else if(sta == INT_POUNDS){
        st = sta;
        i_pounds = (int)lbs;
        f_pounds = (double)(int)lbs;
        set_stone();
    }
    else{
        std::cout << "the Status is a wrong value.\n"
        << " Default set Status to FLOAT_POUNDS and set value to 0.\n";
        st = FLOAT_POUNDS;
        f_pounds = 0.0;
        set_stone();
        set_i_p();

    }
}


Stonewt::Stonewt(int stn, double lbs, Status sta){
    if(sta == STONE){
        st = sta;
        stone = stn;
        left_pds = lbs;
        set_f_p();
        set_i_p();
    }
    else if(sta == FLOAT_POUNDS){
        st = sta;
        stone = stn;
        left_pds = lbs;
        set_f_p();
        set_i_p();
    }
    else if (sta == INT_POUNDS){
        st = sta;
        stone = stn;
        left_pds = lbs;
        set_f_p();
        set_i_p();
    }
    else {
        std::cout << "the Status is a wrong value.\n"
        << " Default set Status to STONE and set value to 0.\n";
        st = STONE;
        stone = 0;
        left_pds = 0.0;
        set_f_p();
        set_i_p();
    }

}


Stonewt::Stonewt(){
    st = STONE;
    stone = 0;
    left_pds = 0.0;
    set_f_p();
    set_i_p();
}

Stonewt::~Stonewt(){

}


std::ostream & operator<<(std::ostream & os, const Stonewt & stonewt){
    if(stonewt.st == Stonewt::STONE){
        os << "stone is " << stonewt.stone << ", left pounds is " << stonewt.left_pds;
    }
    else if(stonewt.st == Stonewt::FLOAT_POUNDS){
        os << "float pounds is " << stonewt.f_pounds;
    }
    else if(stonewt.st == Stonewt::INT_POUNDS){
        os << "int pounds is " << stonewt.i_pounds;
    }
    else{
        os << "Wrong Status!";
    }
    return os;
}


Stonewt operator+(Stonewt & s1, Stonewt & s2){

    Stonewt ns;

    ns.stone = s1.stone + s2.stone + int(s1.left_pds + s2.left_pds)/Stonewt::Lbs_per_stn;
    ns.left_pds = (int) (s1.left_pds + s2.left_pds)%Stonewt::Lbs_per_stn +\
        (s1.left_pds + s2.left_pds)-int(s1.left_pds+s2.left_pds);

    ns.i_pounds = s1.i_pounds + s2.i_pounds;
    ns.f_pounds = s1.f_pounds + s2.f_pounds;

    return ns;
}

Stonewt operator-(Stonewt & s1, Stonewt & s2){
    Stonewt ns;

    ns.stone = s1.stone - s2.stone + int(s1.left_pds - s2.left_pds)/Stonewt::Lbs_per_stn;
    ns.left_pds = (int) (s1.left_pds - s2.left_pds)%Stonewt::Lbs_per_stn +\
        (s1.left_pds - s2.left_pds)-int(s1.left_pds-s2.left_pds);

    ns.i_pounds = s1.i_pounds - s2.i_pounds;
    ns.f_pounds = s1.f_pounds - s2.f_pounds;

    return ns;
}

Stonewt operator*(double d, Stonewt & s){
    Stonewt ns;

    ns.stone = int(s.f_pounds * d) / Stonewt::Lbs_per_stn;
    ns.left_pds = int(s.f_pounds * d) % Stonewt::Lbs_per_stn + s.f_pounds * d - int(s.f_pounds*d);
    ns.i_pounds = int(s.f_pounds*d);
    ns.f_pounds = s.f_pounds*d;

    return ns;
}

Stonewt operator*(Stonewt & s, double d){
    return d*s;
}


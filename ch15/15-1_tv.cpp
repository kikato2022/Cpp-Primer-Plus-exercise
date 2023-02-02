// tv.cpp -- methods for the Tv class (Remote methods are inline)
#include <iostream>
#include "15-1_tv.h"


bool Tv::volup(){
    if (volume < MaxVal){
            volume++;
            return true; 
    }
    else{
        return false;
    }
}

bool Tv::voldown(){
    if(volume > MinVal){
        volume--;
        return true;
    }
    else {
        return false;
    }
}

void Tv::chanup(){
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown(){
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::set_remote_status(Remote & r){
    if(state == On){
        if(r.status == Remote::NORMAL){
            r.status = Remote::INTERRANCTIVE;
        }
        else{
            r.status = Remote::NORMAL;
        }
    }
}

void Tv::settings() const{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if(state == On){
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
             << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
             << (input == TV? "TV" : "DVD") << endl;
    }
}


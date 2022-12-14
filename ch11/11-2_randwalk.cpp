// randwalk.cpp -- using the Vector class
// compile with the vector.cpp file

#include<iostream>
#include<fstream>

#include<cstdlib> // rand(),srand()
#include<ctime> // time();
#include "11-2_vector.h"

int main(){

    using namespace std;
    using namespace VECTOR;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance(q to quit): ";

    while(cin >> target){
        cout << "Enter step length: ";
        if (!(cin >> dstep)) break;

        ofstream fs;
        fs.open("result2.txt");

        if(!fs.is_open()){
            cout << "file open failed." << endl;
            break;
        }

        fs << steps << ": " << result << endl;
        while (result.magval() < target) {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            
            steps++;
            fs << steps << ": " << result << endl;
        }
        fs << "After " << steps << " steps, the subject "
            "hass the following location:\n";
        fs << result << endl;
        result.polar_mode();
        fs << " or\n" << result << endl;
        fs << "Average outward distance per step = "
            << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        
        fs.close();
        cout << "Enter target distance (q to quit): ";

    }


    cout << "Bye!\n";
    cin.clear();
    while(cin.get()!='\n') continue;

    return 0;



}
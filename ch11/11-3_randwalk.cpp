// randwalk.cpp -- using the Vector class
// compile with the vector.cpp file

#include<iostream>

#include<cstdlib> // rand(),srand()
#include<ctime> // time();
#include<climits> // LONG_MAX;

#include "11-3_vector.h"

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
    unsigned int num = 0;

    cout << "Enter target distance(q to quit): ";

    while(cin >> target){
        cout << "Enter step length: ";
        if (!(cin >> dstep)) break;
        cout << "Enter the number of test: ";
        if (!(cin >> num)) break;
 
        unsigned long max=0;
        unsigned long min=LONG_MAX;
        unsigned long total=0;

        // START TEST
        for (int i=0; i<num; i++){
            while (result.magval() < target) {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
                
            }

            if(steps>max) max = steps;
            if(steps<min) min = steps;
            total += steps;

            cout << "After " << steps << " steps, the subject "
                "hass the following location:\n";
            cout << result << endl;
            result.polar_mode();
            cout << " or\n" << result << endl;
            cout << "Average outward distance per step = "
                << result.magval()/steps << endl;

            steps = 0;
            result.reset(0.0, 0.0);
        }
        cout << endl;
        cout << endl;

        cout << "max steps is " << max << ", min steps is " << min << endl;
        cout << "average steps is " << total/num << endl;

        // END TEST
        cout << "Enter target distance (q to quit): ";

    }


    cout << "Bye!\n";
    cin.clear();
    while(cin.get()!='\n') continue;

    return 0;



}
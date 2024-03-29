// error4.cpp -- using exception classes

#include<iostream>
#include<cmath> // or math.h, unix users may need -lm flag
#include"15-3_exc_mean.h"

// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main(){
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";

    while(cin >> x >> y){
        try { // start of try block
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers < q to quit>: ";
        } // end of try block
        catch(bad_mean & bm){ // start of catch block
            bm.mesg();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }

    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b){
    if (a==-b){
        throw bad_hmean("hmean",a,b);
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b){
    if (a < 0 || b < 0){
        throw bad_gmean("gmean",a,b);
    }
    return std::sqrt(a * b);
}
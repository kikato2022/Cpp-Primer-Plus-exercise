// bank.cpp -- using the Queue interface
// compile with queue.cpp

#include <ios>
#include<iostream>
#include<cstdlib>   // for rand() and srand()
#include<ctime> // for time()
#include"12-6_queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer

int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // setting things up
    std::srand(std::time(0));   // random initializing of rand()

    cout << "Case Study, Bank of Heather automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;

    Queue line1(qs);     // line queue holds up to qs people
    Queue line2(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;

    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours;   // # of cycles

    cout << "Enter the average number of customers per hour: ";
    double perhour;     // average # of arrival per hour
    cin >> perhour;
    double min_per_cust;        // average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;          // new customer data
    long turnaways = 0; // turned away by full queue
    long customers = 0; // joined the queue
    long served = 0;    // served during the simulation

    long sum_line = 0;  // cumulative line length

    int wait_time_1 = 0;  // time until autoteller is free
    int wait_time_2 = 0;  // time until autoteller is free

    long line_wait = 0; // cumulative time in line


    // running the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++ ){
        if (newcustomer(min_per_cust)){
            if(line1.isfull() && line2.isfull()){
                turnaways++;
            }
            else{
                if(line1.queuecount()<=line2.queuecount()){
                    customers++;
                    temp.set(cycle);
                    line1.enqueue(temp);
                }else{
                    customers++;
                    temp.set(cycle);
                    line2.enqueue(temp);
                }   
            }
        }
        if (wait_time_1 <= 0 && !line1.isempty()){
            line1.dequeue(temp);
            wait_time_1 = temp.ptime();
            line_wait += cycle-temp.when();
            served++;
        }
        if (wait_time_2 <= 0 && !line1.isempty()){
            line1.dequeue(temp);
            wait_time_2 = temp.ptime();
            line_wait += cycle-temp.when();
            served++;
        }
        
        if(wait_time_1>0)
            wait_time_1--;
        if(wait_time_2>0)
            wait_time_2--;

        sum_line += line1.queuecount();
        sum_line += line2.queuecount();
    }
    if (customers>0){
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit / 2 << endl;
        cout << " average wait time: ";
        cout << (double) line_wait / served << " minutes\n";
    }
    else{
        cout << "No customers!\n";
    }
    cout << "Done!\n";

    return 0;

}

// x = average time, in minutes, between customers
// return value is true if customer shows  this minute
bool newcustomer(double x){
    return (std::rand()*x/RAND_MAX < 1);
}
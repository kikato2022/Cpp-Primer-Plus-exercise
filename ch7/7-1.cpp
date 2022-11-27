#include<iostream>

using namespace std;

double average(double x, double y);

int main() {
	cout << "Please input two number:\n";
	double x,y;
	while(cin>>x>>y){
		if(x==0||y==0) break;
		cout << average(x,y) << endl;
		cout << "Please input two number:\n";
	}
	cout << "End." << endl;

}

double average(double x, double y){
	return 2.0*x*y/(x+y);
}

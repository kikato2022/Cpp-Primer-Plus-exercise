#include<iostream>

using namespace std;

int main(){

	int input;
	cout << "Input your income: ";
	while(cin>>input){
		if(input<0) break;
		double tax;
		if ( input<=5000) tax =0;
		else if ( input <=15000) {
			tax = (input-5000)*0.1;
		}
		else if ( input <= 35000) {
			tax = 10000*0.1 + (input-15000)*0.15;
		}
		else
			tax = 10000*0.1 + 20000*0.15 + (input-35000)*0.2;
		cout << "You shoud pay " << tax <<" tvarp of tax.\n";
		cout << "Input your income: ";
	}
	return 0;
}
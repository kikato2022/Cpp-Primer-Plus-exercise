#include<iostream>
using namespace std;

long long factorial(int num){
	if(num==0) return 1;
	return num*factorial(num-1);
}

int main(){

	cout << "Input a number: ";
	int number;

	while( !(cin>>number) ){
		cout<<"Please input an integer: ";
		cin.clear();
		while(cin.get()!='\n') cin.get();
	}

	cout << "The factorial of this number is: " << factorial(number) << endl;

}
#include<iostream>

using namespace std;

int main(){

	long double result = 1.0;
	long double n;
	unsigned p;
	for(n=47,p=5; p>0; n--,p--)
		result = result*n/p;
	cout << "You have one chance in " << result*27 << " choices.\n";
}
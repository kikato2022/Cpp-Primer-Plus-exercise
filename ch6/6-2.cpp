#include<iostream>

using namespace std;

int main(){

	double arr[10];
	double donation;
	int i=0;
	while( i<10 && cin>>donation){
		arr[i++] = donation;
	}
	if(i==0){
		cout << "no valid input!" << endl;
		return 0;
	}

	double sum = 0.0;
	for(int j=0; j<i;j++){	
		sum += arr[j];
	}

	double average = sum / i;
	int count = 0;
	for(int j = 0; j < i; j++){
		if(arr[j]>average) count++;
	}

	cout << "The average of input nums is: " << average << endl;
	cout << "There are " << count << " nums above average." << endl;
}
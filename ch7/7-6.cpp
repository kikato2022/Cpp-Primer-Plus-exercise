#include<iostream>

using namespace std;

int fill_array(double[], int);
void show_array(double[],int);
void reverse_array(double[],int);


int main(){
	cout << "Input an array: (q to end)";
	double array[20];
	int len = fill_array(array, 20);
	show_array(array, len);
	reverse_array(array,len);
	show_array(array, len);
	reverse_array(array+1,len-2);
	show_array(array,len);

}

int fill_array(double array[], int size){

	for(int i = 0; i<size; i++){
		if(!(cin>>array[i])) return i;
	}
	return size;
}

void show_array(double array[], int size){

	cout << "The array: ";
	for(int i=0; i<size; i++){
		cout << array[i] << " ";
	}
	cout << endl;

}

void reverse_array(double array[], int size){

	int i=0;
	int j = size-1;
	double temp;

	while(i<j){
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
	}

}
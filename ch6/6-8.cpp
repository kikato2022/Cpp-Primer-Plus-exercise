#include<fstream>
#include<iostream>
using namespace std;

int main(){

	cout << "input a filename: ";
	char filename[20];
	cin >> filename;
	ifstream inFile;
	inFile.open(filename);
	char character;
	int num = 0;
	while(inFile>>character) num++;
	cout << "There are " << num << " characters in this file.\n";

}
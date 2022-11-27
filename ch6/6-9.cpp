#include<fstream>
#include<string>
#include<iostream>
#include<cstdlib>

using namespace std;

struct entry{
	string name;
	double money;
};

int main(){
	
	ifstream inFile;
	inFile.open("6-9input.txt");

	if(!inFile.is_open()){
		cout << "Could not open the file " << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}

	int number;
	inFile >> number;
	inFile.get();
	cout << "number is " << number << endl;

	entry* people = new entry[number];
	
	for(int i=0;i<number;i++){
		getline(inFile, people[i].name);
		//cout <<"name is " <<  people[i].name << endl;
		inFile >> people[i].money;
		inFile.get();
		//cout << "money is " << people[i].money << endl;
	}
	
	bool none = true;
	cout << "Grand Patrons: \n";
	for(int i=0;i<number;i++){
		if(people[i].money>=10000){
			cout << people[i].name << "\t" << people[i].money << endl;
			none = false;
		}
	}
	if(none) cout << "none\n";
	cout << endl;

	none = true;
	cout << "Patrons: \n";
	for(int i=0;i<number;i++){
		if(people[i].money<10000){
			cout << people[i].name << "\t" << people[i].money << endl;
			none = false;
		}
	}
	if(none) cout << "none\n";
	delete[] people;
	return 0;

}
#include<iostream>
#include<string>

using namespace std;

struct entry{
	string name;
	double money;
};

int main(){
	
	int number;
	cin >> number;

	entry* people = new entry[number];

	for(int i=0;i<number;i++){
		cout << "name: ";
		cin >> people[i].name;
		cout << "money: ";
		cin >> people[i].money;
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
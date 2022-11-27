#include<iostream>

using namespace std;

const int Seasons = 4;

const char * Snames[4] = 
{"Spring", "Summer", "Fall", "Winter"};


//version1
/*
void fill(double*);
void show(double*);
*/

//version2

struct expenses{
	double ar[Seasons];
};

void fill(expenses*);
void show(const expenses*);



int main(){
	//version1
	/*
	double expense[Seasons];
	fill(expense);
	show(expense);
	*/
	//version2
	expenses exp;
	fill(&exp);
	show(&exp);
	return 0;

}

// version1
/*
void fill ( double *pa ){
	
	for (int i =0; i<Seasons;i++){
		cout << "Enter" << Snames[i] << " expenses: ";
		cin >> pa[i];
	}
}

void show(double * pa){
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++){
		cout << Snames[i] << ": $" << pa[i] << endl;
		total += pa[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
*/

// version2
void fill ( expenses * pe){
	for(int i=0; i<Seasons; i++){
		cout << "Enter" << Snames[i] << " expenses: ";
		cin >> pe->ar[i];
	}
}

void show(const expenses * pe){
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i=0; i<Seasons; i++){
		cout << Snames[i] << ": $" << pe->ar[i] << endl;
		total += pe->ar[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
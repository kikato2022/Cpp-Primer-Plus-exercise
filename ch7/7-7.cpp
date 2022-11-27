#include<iostream>

using namespace std;




const int Max = 5;
double* fill_array(double ar[], int limit);
void show_array(const double ar[], double* last);
void revalue(double r, double ar[],double *last);



int main() {
	using namespace std;
	double properties[Max];

	double *last = fill_array(properties, Max);
	show_array(properties, last);

	if ( last!=properties-1 ){
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin>> factor)){
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, last);
		show_array(properties,last);
	}
	cout << "Done.\n";
	cin.get();
	cout << "Press enter to exit.\n";
	cin.get();
	return 0;


}

double* fill_array(double ar[], int limit){
	using namespace std;
	double temp;
	int i;
	for (i=0; i<limit; i++){
		cout << "Enter value #" << (i+1) << ": ";
		cin >> temp;
		if(!cin){
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp<0)
			break;
		*(ar+i) = temp;
	}
	return ar+i-1;
}


void show_array(const double ar[], double *last){
	using namespace std;
	int i=0;
	while( (ar+i) !=last ){
		cout << "Property #" << i+1 << ": $";
		cout << *(ar+i) << endl;
		i++;
	}
	cout << "Property #" << i+1 << ": $";
	cout << *(ar+i) << endl;
	
}

void revalue(double r, double ar[], double *last){
	for(double * par = ar; par!=last+1;par++){
		(*par) *= r;
	}
}




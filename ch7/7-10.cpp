#include<iostream>

using namespace std;

double add(double x, double y){
	return x+y;
}

double multiply(double x, double y) {
	return x*y;
}

double sub(double x, double y){
	return x-y;
}

double (*pf[3])(double,double) = {add,multiply,sub};


double calculate(double x, double y, double (*p)(double,double)){
	return (*p)(x,y);
}

int main(){
	double x,y;
	cin>>x>>y;
	for(int i =0; i<3; i++){
		cout << calculate(x,y,pf[i]) << endl;
	}
}





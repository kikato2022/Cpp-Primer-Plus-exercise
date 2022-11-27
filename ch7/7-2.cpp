#include<iostream>

using namespace std;

int scores[10];
int score_size = 10;

void input(int [], int *);
void show(int [], int);
double average(int [], int);


int main() {
	
	input(scores,&score_size);
	show(scores,score_size);
	
	cout << "average: "<< average(scores,score_size);

}

void input(int scores[],  int * size){
	int i;
	for(i=0; i<10;i++){
		if(cin>>scores[i]) continue;
		else break;
	}
	*size = i;
}

void show(int scores[], int size){
	cout << "scores: ";
	for(int i=0; i<size;i++) 
		cout << scores[i] << " ";
	cout << endl;
}

double average(int scores[], int size){
	double result = 0.0;
	for(int i=0; i<size; i++) result += scores[i];
	return result/size;
}



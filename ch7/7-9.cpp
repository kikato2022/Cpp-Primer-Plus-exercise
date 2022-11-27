#include<iostream>
#include<cstring>

using namespace std;

const int SLEN = 30;

struct student  {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);

void display1(student st);

void display2(const student *ps);

void display3(const student pa[], int n);

int main(){
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n') continue;

	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++){
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done\n";
	return 0;
}

int getinfo(student pa[], int n){
	int i;
	for (i = 0; i < n; i++){
		cout << "Input # " << i+1 << " student info: ";
		cout << "name: ";
		cin.getline(pa[i].fullname,SLEN);
		if (strlen(pa[i].fullname)==0) {
			cout << "INPUT END" << endl;
			break;
		}
		//while(cin.get()!='\n') continue;
		cout << "hobby: ";
		cin.getline(pa[i].hobby,SLEN);
		//while(cin.get()!='\n') continue;
		cout << "ooplevel: ";
		while(!(cin >> pa[i].ooplevel)){
			cout << "Please input an integer." << endl;
		}
		cin.get();
	}
	return i;
}

void display1(student st){
	cout << st.fullname << "'s hobby is "<< st.hobby;
	cout << ", ooplevel is " << st.ooplevel << "."<<endl;
}

void display2(const student *ps){
	cout << ps->fullname << "'s hobby is "<< ps->hobby;
	cout << ", ooplevel is " << ps->ooplevel << "."<<endl;
}

void display3(const student pa[], int n){
	for (int i = 0; i<n; i++){
		cout << pa[i].fullname << "'s hobby is "<< pa[i].hobby;
		cout << ", ooplevel is " << pa[i].ooplevel << "."<<endl;
	}
}
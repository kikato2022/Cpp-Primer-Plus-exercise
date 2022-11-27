#include<iostream>

using namespace std;

const int Strsize = 20;

struct Bop{

	char fullname[Strsize];
	char title[Strsize];
	char bopname[Strsize];
	int preference;	// 0 = fullname, 1 = title, 2 = bopname
};

int main(){

 	Bop bop[5]= {
		{"William Job", "boss",  "MIPS", 0},
		{"celia coc", "manager", "LOOPY", 2},
		{"ieo ieojlib", "coach", "analyst",1},
		{"k rie lsl", "oeit", "joweihf" ,1},
		{"it llei iiii", "ioth", "ot", 2}
	};
	cout << "Benevolent Order of Programmers Report\n";
	cout << "a.  display by name\t\t b.  display by title\n";
	cout << "c.  display by bopname\t\t d.  display by preference\n";
	cout << "q.  quit\n";
	cout << "Enter your choice: ";
	
	char choice;

	while( cin >> choice){
		if(choice == 'q') {
			cout << "Bye!\n";
			break;
		}
		switch(choice){
			case 'a': 	for (int i=0;i<5;i++)
					cout << bop[i].fullname << endl;
				cout << "Next choice: ";
				break;
			case 'b':	for (int i=0; i<5; i++)
					cout << bop[i].title << endl;
				cout << "Next choice: ";
				break;
			case 'c':	for (int i=0; i<5; i++)
					cout << bop[i].bopname << endl;
				cout << "Next choice: ";
				break;
			case 'd':	for (int i=0; i<5; i++){
					if(bop[i].preference==0) cout << bop[i].fullname << endl;
					else if (bop[i].preference==1) cout << bop[i].title << endl;
					else if (bop[i].preference==2) cout << bop[i].bopname << endl;
				}
				cout << "Next choice: ";
				break;
			default:	cout << "Please input a right choice: ";
		}
	}

	return 0;
}
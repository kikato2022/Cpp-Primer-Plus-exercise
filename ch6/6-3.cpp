#include<iostream>

using namespace std;

int main() {
	
	cout << "Please enter one of the following choices:\n";
	cout << "c)  carnivore\t\tp)  pianist\n";
	cout << "t)  tree\t\tg)  game\n";

	char choice;

	while (cin>>choice) {
		if(choice=='c'||choice=='p'||choice=='t'||choice=='g'){
			switch (choice){
				case 'c': 	cout << "a terrestrial or aquatic flesh-eating mammal.\n";
					break;
				case 'p':	cout << "a person who plays the piano.\n";
					break;
				case 't':	cout << "a figure that branches from a single root.\n";
					break;
				case 'g':	cout << "a single play of a sport or other contest.\n";
					break;
			}
			break;
		}
		else{
			cout  << "Please enter c, p, t, or g: ";
		}
	}

	return 0;
	
}



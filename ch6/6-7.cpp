#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

int main() {

	char word[50];
	int vowel_num=0;
	int abjad_num=0;
	int other_num=0;
	while(cin>>word){
		if(strlen(word)==1&&word[0]=='q')
			break;
		if(isalpha(word[0])){
			switch (word[0]){
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u': 	vowel_num++;
					break;
				default: 	abjad_num++;
					break;
			}
		}
		else{
			other_num++;
		}
	}
	cout << vowel_num << " words beginning with vowels\n";
	cout << abjad_num << " words beginning with consonants\n";
	cout << other_num << " others\n";

	return 0;

}
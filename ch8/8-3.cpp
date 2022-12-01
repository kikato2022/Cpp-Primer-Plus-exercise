#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cout << "Enter a string (q to quit):";
    getline(cin,str);

    while(str!="q"){
        for(int i=0;i<str.size();i++){
            str[i] = toupper(str[i]);
        }
        cout << str << endl;
        cout << "Next string (q to quit):";
        getline(cin, str);
    }

    cout << "Bye." << endl;
    return 0;
}
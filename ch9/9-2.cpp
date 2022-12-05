// static.cpp -- using a static local variable
#include<iostream>
#include<string>
// constrants
const int ArSize = 10;
// function prototype
void strcount(std::string);

int main(){
    using namespace std;
    string input;
    cout << "Enter a line:\n";
    getline(cin,input);
    while(input!=""){
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin,input);
    }
    cout << "Bye\n";
    return 0;

}

void strcount(std::string str){
    using std::cout;
    static int total = 0;
    cout << "\"" << str << "\" contains ";
    cout << str.size() << " charactors\n";
    total+=str.size();
    cout << total << " charactors total\n";
}
#include <cstdlib>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>


int main() {
    using namespace std;

    ifstream matin("mat.dat", ios_base::in);
    ifstream patin("pat.dat", ios_base::in);

    if(!(matin && patin)){
        cerr << "Failed to open input files.\n";
        exit(EXIT_FAILURE);
    }


    ofstream matnpatout("matnpat.dat", ios_base::out);
    if(!matnpatout.is_open()){
        cerr << "Failed to open output files.\n";
        exit(EXIT_FAILURE);
    }

    vector<string> mat;
    vector<string> pat;
    string name;

    while(!matin.eof()) {       
        getline(matin, name);
        mat.push_back(name);
    }
    cout << "Success" << endl;
    while(!patin.eof()) {
        
        getline(patin, name);
        pat.push_back(name);
    }

    cout << "Mat's friends:\n";
    for(auto& name : mat){
        cout << name << endl;
    }
    cout << "Pat's friends:\n";
    for(auto& name : pat) {
        cout << name << endl;
    }

    set<string> matnpat;
    matnpat.insert(mat.begin(), mat.end());
    matnpat.insert(pat.begin(), pat.end());
    for(auto& name : matnpat) {
        matnpatout << name << endl;
    }

    return 0;
}
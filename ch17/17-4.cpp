#include <cstdlib>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char* argv[]) {

    if(argc!=4){
        cerr << "Usage: " << argv[0] << " <source file1> <source file2> <target file>.\n";
        exit(EXIT_FAILURE);
    }
    ifstream ifs1(argv[1], ios_base::in);
    ifstream ifs2(argv[2], ios_base::in);
    ofstream ofs(argv[3], ios_base::out);

    if(!ifs1.is_open()) {
        cerr << "Error when open " << argv[1] << ".\n";
    }
    if(!ifs2.is_open()) {
        cerr << "Error when open " << argv[2] << ".\n";
    }

    string line1, line2;
    getline(ifs1, line1);
    getline(ifs2,line2);
    while(line1.size() >0 && line2.size() >0 ){
        ofs << line1 << ' ' << line2 << endl;
        getline(ifs1, line1);
        getline(ifs2,line2);
    }
    if(!ifs1.eof()){
        while(line1.size()>0){
            ofs << line1 << endl;
            getline(ifs1, line1);
        }
    }
    if(!ifs2.eof()){
        while(line2.size()>0){
            ofs << line2 << endl;
            getline(ifs2, line2);
        }
    }

    return 0;
}
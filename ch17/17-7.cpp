#include <cstddef>
#include <cstdlib>
#include <ios>
#include<iostream>
#include<fstream>
#include <ostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Store {
private:
    ostream &os;
public:
    Store(ostream &o):os(o){}
    void operator()(const string & s){
        size_t len = s.length();
        os.write((const char *)&len, sizeof(std::size_t));
        os.write(s.data(),len);
    }
};

inline void ShowStr(const std::string& s) {
    cout << s << endl;
}

void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr);

int main(){
    using namespace std;
    vector<string> vostr;
    string temp;

    // acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while(getline(cin, temp)&&temp.size()>0){
        vostr.push_back(temp);
    }
    for_each(vostr.begin(), vostr.end(), ShowStr);

    // store in a file
    ofstream fout("string.dat", ios_base::out|ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    cin.get();

    // recover file contents
    vector<string> vistr;
    ifstream fin("string.dat", ios_base::in|ios_base::binary);
    if (!fin.is_open()){
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(),ShowStr);

    return 0;

}

void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr){
    size_t len;     // string length
    while(fin.read( (char*)&len, sizeof(size_t) ) ){
        string str;
        char ch;
        for(int i=0; i< len; i++){
            fin.read(&ch,sizeof(char));
            str.push_back(ch);
        }
        vistr.push_back(str);
    }
}
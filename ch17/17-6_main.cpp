#include"17-6_emp.h"
#include <fstream>


using namespace std;

inline void showline(int n);
void show_menu();
inline void eatline();

const int MAX = 10;

int main() {
    ab_emp* pc[MAX];
    int ct; // number counter

    string fname, lname, job, reportsto;
    int inchargeof;

    // read from file
    ifstream fin("out.txt", ios_base::in);
    if(fin.is_open()){
        int kind;
        while(fin>>kind){
            switch (kind) {
            case Employee:
                fin >> fname;
                fin >> lname;
                fin >> job;
                pc[ct] = new employee(fname, lname, job);
                break;
            case Manager:
                fin >> fname;
                fin >> lname;
                fin >> job;
                fin >> inchargeof;
                pc[ct] = new manager(fname, lname, job, inchargeof);
                break;
            case Fink:
                fin >> fname;
                fin >> lname;
                fin >> job;
                fin >> reportsto;
                pc[ct] = new fink(fname, lname, job, reportsto);
                break;
            case Highfink:
                fin >> fname;
                fin >> lname;
                fin >> job;
                fin >> reportsto;
                fin >> inchargeof;
                pc[ct] = new highfink(fname, lname, job, reportsto, inchargeof);
                break;
            }
            ct++;
        }
        cout << "content in out.txt: " << endl;
        for(int i=0; i<ct; i++){
            pc[i]->ShowAll();
        }
        fin.close();
    }



    // add elements
    char choice;

    show_menu();
    while(cin>>choice && choice!='q' && ct<MAX){
        eatline();
        switch (choice) {
        case 'e':
            pc[ct] = new employee;
            pc[ct]->SetAll();
            break;
        case 'm':
            pc[ct] = new manager;
            pc[ct]->SetAll();
            break;
        case 'f':
            pc[ct] = new fink;
            pc[ct]->SetAll();
            break;
        case 'h':
            pc[ct] = new highfink;
            pc[ct]->SetAll();
            break;
        }
        ct++;
        show_menu();
    }
    for(int i=0 ; i<ct; i++){
        pc[i]->ShowAll();
    }

    // write to file
    ofstream fout("out.txt", ios_base::out);
    for(int i=0; i<ct; i++){
        pc[i]->WriteAll(fout);
        fout << endl;
    }
    fout.close();

    cout << "all contents written to out.txt\n";

    for(int i=0; i<ct;i++){
        delete pc[i];
    }

    return 0;

}



void show_menu(){
    ios_base::fmtflags old_fmt = cout.setf(ios_base::left, ios_base::adjustfield);

    showline(35);
    cout.width(20);
    cout << "e. employee";
    cout << "m. manager" << endl;
    cout.width(20);
    cout << "f. fink";
    cout << "h. highfink" << endl;
    cout << "q. quit" << endl;
    showline(35);
    cout << "Select a type: " << endl;

    cout.setf(old_fmt);
}

inline void showline(int n){
    cout.fill('-');
    cout.width(n);
    cout << "-" << endl;
    cout.fill(' ');
}

inline void eatline() {
    while(cin.get() != '\n') continue;
}
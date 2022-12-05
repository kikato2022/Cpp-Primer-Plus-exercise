#include<iostream>


struct chaff{
    char dross[20];
    int slag;
};

char buffer[512];

int main(){
    using std::cout;
    using std::cin;
    chaff * arr = new(buffer) chaff[2];

    int i;
    for(i=0; i<2; i++){
        cout << "Enter dross: ";
        cin.getline(arr[i].dross,20);
        if(cin.fail()){
            //cout << "fail" << std::endl;
            //std::string s;
            char m = cin.get();
            cout << "m is " << m << std::endl;
            char n = cin.get();
            cout << "n is " << n << std::endl;
            //cin.clear();
            cin.clear();
            char o = cin.get();
            cout << "o is " << o << std::endl;
            char p = cin.get();
            if(p=='\n') cout << "line end" << std::endl;
            
            while(cin.get()!='\n') continue;
            //getline(cin,s);
            //cout << "in cin buffer: " << s << std::endl;
        }
        //cin.ignore(100,'\0');
        //cin.ignore('\n');
        //char m;
        //m = getchar();
        //cout << "m is: " << m << std::endl;
        //char n;
        //n = getchar();
        //cout << "n is: " << n << std::endl;
        //while(cin.get()!='\0') continue;
        //while(cin.get()!='\n') continue;
        cout << "Enter slag: ";
        //while(cin.get()!='\n') continue;
        //char m[20];
        //cin >> m;
        //cout << "m is: " << m << std::endl;
        //cin.clear();
        while(!(cin>>arr[i].slag)){
            cin.clear();
            //cin.ignore(100,'\n');
            while(cin.get()!='\n');
            cout << "Please input an integer: ";    
        }
        cin.ignore(100,'\n');
        //while(cin.get()!='\n') continue;
        cout << std::endl;
    }

    cout << "The array is: \n";
    for(i=0; i<2; i++){
        cout << i << ": dross: " << arr[i].dross << ", slag: " << arr[i].slag << "\n";
    }

}

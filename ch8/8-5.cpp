#include<iostream>

using namespace std;

template<typename T>
T max5(T * t){
    T max = t[0];
    for(int i=1;i<5;i++){
        if(max<t[i]) max = t[i];
    }
    return max;
}

int main(){
    int a[5] = {1,4,5,2,3};
    double b[5] = {3.14,2.73,1e10,-2.3,1.1111};

    cout << "Max of a is " << max5(a) << endl;
    cout << "Max of b is " << max5(b) << endl;

    return 0;
}
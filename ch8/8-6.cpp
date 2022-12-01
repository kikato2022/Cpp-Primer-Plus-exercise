#include<iostream>
#include<cstring>

using namespace std;

template<typename T>
T maxn(T * t, int num){
    T max = t[0];
    for(int i=1;i<num;i++){
        if(max<t[i]) max = t[i];
    }
    return max;
}

template<> char* maxn<char*>(char ** a, int num){
    int max = strlen(a[0]);
    int mark = 0;
    int i;
    for(i=1; i<num; i++){
        if(max<strlen(a[i])) {
            max = strlen(a[i]);
            mark = i;
        }
    }
    return a[i];
}

int main(){
    int a[6] = {1,4,5,2,3,6};
    double b[4] = {3.14,2.73,1e10,-2.3};
    const char * c[5] = {
        "xxxxxxxsss",
        "bbeighsssssss",
        "coitstssssssssssss",
        "csssssss",
        "xxxxx"
    };

    cout << "Max of a is " << maxn(a,sizeof(a)/sizeof(a[0])) << endl;
    cout << "Max of b is " << maxn(b,sizeof(b)/sizeof(b[0])) << endl;
    cout << "Max of c is " << (long long)maxn(c, sizeof(c)/sizeof(c[0])) << endl;

    return 0;
}
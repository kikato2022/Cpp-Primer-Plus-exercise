#include"11-5_stonewt.h"

int main(){
    using std::cout;
    using std::endl;
    Stonewt a(10,11);
    Stonewt b(11.3);

    cout << "a is " << a << endl;
    cout << "b is " << b << endl;

    cout << "a + b is " << a + b << endl;
    cout << "a - b is " << a - b << endl;
    cout << "a * 2 is " << a * 2 << endl;
    cout << "2 * a is " << 2 * a << endl;

}
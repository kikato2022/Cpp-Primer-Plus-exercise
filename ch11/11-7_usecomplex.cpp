#include"11-7_complex.h"

int main(){

    using std::cout;
    using std::cin;
    using std::endl;
    Complex a(3.0, 4.0);
    Complex c;
    cout << "Enter a complex number (q to quit):\n";

    while(cin>>c){

        cout << "c is " << c << endl;

        cout << "complex conjugate is " << ~c << endl;

        cout << "a is " << a << endl;
        Complex z = a + c;
        cout << "a + c is " << a + c << endl;
        cout << "a - c is " << a - c << endl;
        cout << "a * c is " << a * c << endl;
        cout << "2 * c is " << 2 * c << endl;
        cout << "Enter a complex number (q to quit):\n";

    }

    cout << "Done!\n";
    return 0;
}
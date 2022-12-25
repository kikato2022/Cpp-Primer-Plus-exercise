#include"12-1_cow.h"

int main(){

    Cow a;
    Cow b("b", "dance", 15);
    Cow c = b;
    Cow d(c);
    a = d;

    a.ShowCow();
    b.ShowCow();
    c.ShowCow();
    d.ShowCow();

    return 0;
}
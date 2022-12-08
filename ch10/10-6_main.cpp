#include"10-6_move.h"

int main(){

    Move m;
    m.showmove();

    Move n(1,1);
    n.showmove();

    m.reset(2, 2);
    m.showmove();

    Move p = m.add(n);
    p.showmove();

    return 0;
    
}
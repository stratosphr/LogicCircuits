#include <iostream>
#include "gate.h"

using namespace std;

int main(){

    Gate g1("and");
    Gate g2("not");
    Gate g3("or");
    Gate g4("xor");

    g3.addSuccessor(g4);
    g3.addSuccessor(g2);
    g1.addSuccessor(g2);
    g1.addSuccessor(g3);
    g1.addSuccessor(g4);
    g1.display();

    return 0;
}

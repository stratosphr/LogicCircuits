#include <iostream>
#include "andGate.h"
#include "notGate.h"

using namespace std;

int main(){

    Gate R0("R", false);
    Gate R1("R", true);

    Gate S0("S", false);
    Gate S1("S", true);

    AndGate and1("and1");
    AndGate and2("and2");
    NotGate not1("not1");
    NotGate not2("not2");
    and1.addSuccessor(&not1);
    and2.addSuccessor(&not2);
    not1.addSuccessor(&and2);
    not2.addSuccessor(&and1);

    /* !S = 0, !R = 1 */
    S1.addSuccessor(&and1);
    R0.addSuccessor(&and2);

    and1.start();
    not1.start();
    and2.start();
    not2.start();

    while(true){
        not1.display();
        not2.display();
    }

}

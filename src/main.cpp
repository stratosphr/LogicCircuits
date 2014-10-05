#include <iostream>
#include "andGate.h"
#include "orGate.h"
#include "notGate.h"
#include "thread.h"
#include "clockGate.h"

using namespace std;

int main(){

    Gate R0("R", false);
    Gate R1("l", true);

    Gate S0("S", false);
    Gate S1("S", true);

    OrGate or1("or1");
    OrGate or2("or2");
    NotGate not1("not1");
    NotGate not2("not2");
    or1.addSuccessor(&not1);
    or2.addSuccessor(&not2);
    not1.addSuccessor(&or2);
    not2.addSuccessor(&or1);

    R1.addSuccessor(&or1);
    S0.addSuccessor(&or2);

    or1.start();
    or2.start();
    not1.start();
    not2.start();

    while(true){
        not1.display();
        not2.display();
    }

}

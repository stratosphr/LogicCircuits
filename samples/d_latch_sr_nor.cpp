#include <iostream>
#include "trueGate.h"
#include "falseGate.h"
#include "notGate.h"
#include "andGate.h"
#include "orGate.h"
#include "watch.h"
#include <unistd.h>

int main(int argc, char* argv[]){

    (void) argc;
    (void) argv;

    FalseGate D0("D0");
    TrueGate D1("D1");
    FalseGate E0("E0");
    TrueGate E1("E1");

    NotGate not1("not1");
    AndGate and1("and1");
    AndGate and2("and2");
    OrGate or1("or1");
    OrGate or2("or2");
    NotGate not2(" Q");
    NotGate not3("/Q");

    E1.addSuccessor(&and1);
    E1.addSuccessor(&and2);
    D1.addSuccessor(&not1);
    D1.addSuccessor(&and2);
    not1.addSuccessor(&and1);
    and1.addSuccessor(&or1);
    and2.addSuccessor(&or2);
    or1.addSuccessor(&not2);
    or2.addSuccessor(&not3);
    not2.addSuccessor(&or2);
    not3.addSuccessor(&or1);

    // Prints the first state
    not2.display();
    not3.display();
    usleep(2000000);

    // Prints the new states
    Watch watch1(&not2);
    Watch watch2(&not3);

    D0.join();
    D1.join();
    E0.join();
    E1.join();
    not1.join();
    and1.join();
    and2.join();
    or1.join();
    or2.join();
    not2.join();
    not3.join();

    return 0;
}

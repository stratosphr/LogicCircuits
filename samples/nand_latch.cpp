#include <iostream>
#include "trueGate.h"
#include "falseGate.h"
#include "notGate.h"
#include "andGate.h"
#include "watch.h"
#include <unistd.h>

int main(int argc, char* argv[]){

    (void) argc;
    (void) argv;

    FalseGate _R0("_R0");
    TrueGate _R1("_R1");
    FalseGate _S0("_S0");
    TrueGate _S1("_R0");

    AndGate and1("and1");
    NotGate not1(" Q");
    AndGate and2("and2");
    NotGate not2("/Q");

    _S1.addSuccessor(&and1);
    and1.addSuccessor(&not1);
    not1.addSuccessor(&and2);
    _R1.addSuccessor(&and2);
    and2.addSuccessor(&not2);
    not2.addSuccessor(&and1);

    // Prints the first state
    usleep(2000000);
    not1.display();
    not2.display();
    usleep(2000000);

    // Prints the new states
    Watch watch1(&not1);
    Watch watch2(&not2);

    _R0.join();
    _R1.join();
    _S0.join();
    _S1.join();
    and1.join();
    not1.join();
    and2.join();
    not2.join();

    return 0;
}

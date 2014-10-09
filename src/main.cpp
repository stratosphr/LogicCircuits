#include <iostream>
#include "clockGate.h"
#include "trueGate.h"
#include "falseGate.h"
#include "notGate.h"
#include "orGate.h"
#include "andGate.h"
#include "watch.h"
#include <thread>
#include <unistd.h>

int main(int argc, char* argv[]){

    (void) argc;
    (void) argv;

    TrueGate R1("R1");
    FalseGate R0("R0");
    TrueGate S1("S1");
    FalseGate S0("S0");

    OrGate or1("or1");
    NotGate not1(" Q");
    OrGate or2("or2");
    NotGate not2("/Q");

    R0.addSuccessor(&or1);
    or1.addSuccessor(&not1);
    not1.addSuccessor(&or2);
    S0.addSuccessor(&or2);
    or2.addSuccessor(&not2);
    not2.addSuccessor(&or1);

    // Prints the first state
    usleep(2000000);
    not1.display();
    not2.display();
    usleep(2000000);

    // Prints the new states
    Watch watch1(&not1);
    Watch watch2(&not2);

    R1.join();
    R0.join();
    S1.join();
    S0.join();
    or1.join();
    not1.join();
    or2.join();
    not2.join();

    return 0;
}

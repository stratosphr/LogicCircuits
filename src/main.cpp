#include <iostream>
#include "clockGate.h"
#include "trueGate.h"
#include "falseGate.h"
#include "andGate.h"

int main(int argc, char* argv[]){

    (void) argc;
    (void) argv;

    ClockGate clock1("clock1", true, 0.25);
    ClockGate clock2("clock2", true, 0.25);
    FalseGate false1("false1");
    TrueGate true1("true1");
    AndGate and1;

    clock1.addSuccessor(&and1);
    clock2.addSuccessor(&and1);

    and1.join();
    clock1.join();
    false1.join();
    true1.join();
    clock2.join();

    return 0;
}

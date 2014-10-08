#include <iostream>
#include "clockGate.h"
#include "trueGate.h"
#include "falseGate.h"
#include "notGate.h"
#include "watch.h"
#include <thread>

int main(int argc, char* argv[]){

    (void) argc;
    (void) argv;

    ClockGate clock1("clock1", true, 1);
    FalseGate false1("false1");
    TrueGate true1("true1");
    NotGate not1;

    Watch watch2(&clock1);
    Watch watch1(&not1);

    clock1.addSuccessor(&not1);

    not1.join();
    clock1.join();
    false1.join();
    true1.join();

    return 0;
}

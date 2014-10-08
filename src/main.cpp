#include <iostream>
#include "trueGate.h"
#include "falseGate.h"
#include "andGate.h"

int main(int argc, char* argv[]){

    TrueGate true1("true1");
    FalseGate false1("false1");
    AndGate and1;

    false1.addSuccessor(&and1);
    true1.addSuccessor(&and1);

    true1.join();
    false1.join();
    and1.join();

    return 0;
}

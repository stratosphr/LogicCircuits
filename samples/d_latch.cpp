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

    FalseGate D0("D0");
    TrueGate D1("D1");
    FalseGate E0("E0");
    TrueGate E1("E1");

    AndGate and1("and1");
    NotGate not1("not1");
    AndGate and2("and2");
    NotGate not2("not2");
    AndGate and3("and3");
    NotGate not3(" Q");
    AndGate and4("and4");
    NotGate not4("/Q");

    and1.addSuccessor(&not1);
    and2.addSuccessor(&not2);
    not1.addSuccessor(&and2);
    not1.addSuccessor(&and3);
    not2.addSuccessor(&and4);
    and3.addSuccessor(&not3);
    and4.addSuccessor(&not4);
    not3.addSuccessor(&and4);
    not4.addSuccessor(&and3);
    D1.addSuccessor(&and1);
    E0.addSuccessor(&and1);
    E0.addSuccessor(&and2);

    // Prints the first state
    not3.display();
    not4.display();
    usleep(2000000);

    // Prints the new states
    Watch watch1(&not3);
    Watch watch2(&not4);

    D0.join();
    D1.join();
    E0.join();
    E1.join();
    and1.join();
    not1.join();
    and2.join();
    not2.join();
    and3.join();
    not3.join();
    and4.join();
    not4.join();

    return 0;
}

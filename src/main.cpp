#include <iostream>
#include "andGate.h"
#include "orGate.h"
#include "notGate.h"
#include "thread.h"

using namespace std;

int main(){

    Gate true1("true", true);
    Gate true2("true", true);

    Gate false1("false", false);
    Gate false2("false", false);

    /* AND */
    AndGate and1;
    true1.addSuccessor(&and1);
    true2.addSuccessor(&and1);
    true1.addSuccessor(&and1);
    and1.display();

    /* OR */
    OrGate or1;
    true1.addSuccessor(&or1);
    false1.addSuccessor(&or1);
    false1.addSuccessor(&or1);
    false2.addSuccessor(&or1);
    or1.display();

    /* NOT */
    NotGate not1;
    true2.addSuccessor(&not1);
    true1.addSuccessor(&not1);
    not1.display();

    /* NOT AND */
    NotGate not2;
    and1.addSuccessor(&not2);
    and1.display();

    true1.start();
    false1.start();
    and1.start();
    or1.start();
    not1.start();
    not2.start();

    while(true){
        and1.display();
    }

    true1.join();
    false1.join();
    and1.join();
    or1.join();
    not1.join();
    not2.join();

    return 0;
}

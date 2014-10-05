#include <iostream>
#include "andGate.h"
#include "orGate.h"
#include "notGate.h"

using namespace std;

bool notFunction(std::vector<bool> ancestorOutputs){
    if(ancestorOutputs.size() == 0){
        return true;
    }else{
        return !ancestorOutputs[0];
    }
}

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

    return 0;
}

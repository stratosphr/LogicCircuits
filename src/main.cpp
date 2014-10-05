#include <iostream>
#include "gate.h"

using namespace std;

bool notFunction(std::vector<bool> ancestorOutputs){
    if(ancestorOutputs.size() == 0){
        return true;
    }else{
        return !ancestorOutputs[0];
    }
}

bool andFunction(std::vector<bool> ancestorOutputs){
    if(ancestorOutputs.size() == 0){
        return false;
    }else{
        bool ret = true;
        for(unsigned int i=0; i<ancestorOutputs.size(); i++){
            ret = ret && ancestorOutputs[i];
        }
        return ret;
    }
}

int main(){

    Gate true1("true", true);
    Gate true2("true", true);
    Gate true3("true", true);
    Gate false1("false", false);
    Gate false2("false", false);
    Gate false3("false", false);

    Gate not1("not1");
    not1.setOutputFunction(notFunction);
    Gate and1("and1");
    and1.setOutputFunction(andFunction);

    true1.addSuccessor(&and1);
    true2.addSuccessor(&and1);
    true3.addSuccessor(&and1);
    and1.display();

    return 0;
}

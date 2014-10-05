#include <iostream>
#include "notGate.h"

NotGate::NotGate(const char* name):
    Gate(name, false)
{
    setOutputFunction(NotGate::notFunction);
}

bool NotGate::notFunction(std::vector<bool> ancestorOutputs){
    if(ancestorOutputs.size() == 0){
        return true;
    }else{
        return !ancestorOutputs[0];
    }
}

#include "orGate.h"

OrGate::OrGate(const char* name):
    Gate(name, false)
{
    setOutputFunction(OrGate::orFunction);
}

bool OrGate::orFunction(std::vector<bool> ancestorOutputs){
    if(ancestorOutputs.size() == 0){
        return false;
    }else{
        for(unsigned int i=0; i<ancestorOutputs.size(); i++){
            if(ancestorOutputs[i] == true){
                return true;
            }
        }
        return false;
    }
}

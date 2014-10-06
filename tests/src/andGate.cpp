#include "andGate.h"

AndGate::AndGate(const char* name):
    Gate(name, false)
{
    setOutputFunction(AndGate::andFunction);
}

bool AndGate::andFunction(std::vector<bool> ancestorOutputs){
    if(ancestorOutputs.size() == 0){
        return false;
    }else{
        for(unsigned int i=0; i<ancestorOutputs.size(); i++){
            if(ancestorOutputs[i] == false){
                return false;
            }
        }
        return true;
    }
}

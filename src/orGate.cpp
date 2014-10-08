#include "orGate.h"

OrGate::OrGate(const char* name):
    Gate(name, false)
{
}

bool OrGate::evaluateOutput() const{
    for(unsigned int i=0; i<m_ancestors.size(); i++){
        if(m_ancestors[i]->getOutput()){
            return true;
        }
    }
    return false;
}

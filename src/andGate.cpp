#include "andGate.h"

AndGate::AndGate(const char* name):
    Gate(name, false)
{
}

bool AndGate::evaluateOutput() const{
    for(unsigned int i=0; i<m_ancestors.size(); i++){
        if(!m_ancestors[i]->getOutput()){
            return false;
        }
    }
    return true;
}

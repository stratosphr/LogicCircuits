#include "notGate.h"

NotGate::NotGate(const char* name):
    Gate(name, true)
{
}

bool NotGate::evaluateOutput() const{
    if(m_ancestors.size() > 0){
        return !m_ancestors[0]->getOutput();
    }
    return true;
}

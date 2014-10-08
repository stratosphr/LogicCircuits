#include "falseGate.h"

FalseGate::FalseGate(const char* name):
    Gate(name, false)
{
}

bool FalseGate::evaluateOutput() const{
    return false;
}

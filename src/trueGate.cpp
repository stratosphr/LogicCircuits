#include "trueGate.h"

TrueGate::TrueGate(const char* name):
    Gate(name, true)
{
}

bool TrueGate::evaluateOutput() const{
    return true;
}

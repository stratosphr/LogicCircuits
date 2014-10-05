#ifndef ORGATE_H
#define ORGATE_H

#include "gate.h"

class OrGate: public Gate{

    public:

        OrGate(const char* name = "or");

    private:

        static bool orFunction(std::vector<bool> ancestorOutputs);

};

#endif

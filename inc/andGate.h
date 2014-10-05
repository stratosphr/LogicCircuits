#ifndef ANDGATE_H
#define ANDGATE_H

#include "gate.h"

class AndGate: public Gate{

    public:

        AndGate(const char* name = "and");

    private:

        static bool andFunction(std::vector<bool> ancestorOutputs);

};

#endif

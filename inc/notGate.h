#ifndef NOTGATE_H
#define NOTGATE_H

#include "gate.h"

class NotGate: public Gate{

    public:

        NotGate(const char* name = "not");

    private:

        static bool notFunction(std::vector<bool> ancestorOutputs);

};

#endif

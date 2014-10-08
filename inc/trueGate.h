#ifndef TRUEGATE_H
#define TRUEGATE_H

#include "gate.h"

class TrueGate: public Gate{

    public:

        TrueGate(const char* name = "true");

    private:

        virtual bool evaluateOutput() const;

};

#endif

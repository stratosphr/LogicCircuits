#ifndef FALSEGATE_H
#define FALSEGATE_H

#include "gate.h"

class FalseGate: public Gate{

    public:

        FalseGate(const char* name = "false");

    private:

        virtual bool evaluateOutput() const;

};

#endif

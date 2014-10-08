#ifndef ANDGATE_H
#define ANDGATE_H

#include <gate.h>

class AndGate: public Gate{

    public:

        AndGate(const char* name = "and");

    private:

        virtual bool evaluateOutput() const;

};

#endif

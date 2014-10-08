#ifndef NOTGATE_H
#define NOTGATE_H

#include <gate.h>

class NotGate: public Gate{

    public:

        NotGate(const char* name = "not");

    private:

        virtual bool evaluateOutput() const;

};

#endif

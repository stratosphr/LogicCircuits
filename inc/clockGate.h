#ifndef CLOCKGATE_H
#define CLOCKGATE_H

#include "gate.h"

class ClockGate: public Gate{

    public:

        ClockGate(const char* name = "clock", const bool startOutput = "false", double frequency = 1);
        virtual void run();
        void update();

    private:

        double m_frequency;
        virtual bool evaluateOutput() const;

};

#endif

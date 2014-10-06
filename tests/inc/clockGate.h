#ifndef CLOCKGATE_H
#define CLOCKGATE_H

#include "gate.h"

class ClockGate: public Gate{

    public:

        ClockGate(const char* name = "clock", double frequency = 1);
        virtual void run();
        void setFrequency(double frequency);

    private:

        double m_frequency;
        static bool clockFunction(std::vector<bool> ancestorOutputs);

};

#endif

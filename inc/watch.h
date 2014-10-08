#ifndef WATCH_H
#define WATCH_H

#include "gate.h"
#include "thread.h"

class Watch: public Thread{

    public:

        Watch(Gate* gateToWatch);
        virtual void run();

    private:

        Gate* m_gateToWatch;

};

#endif

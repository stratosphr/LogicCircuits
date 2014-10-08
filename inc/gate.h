#ifndef GATE_H
#define GATE_H

#include <vector>
#include "thread.h"

class Gate: public Thread{

    public:

        Gate(const char* name, const bool defaultOutput = false);
        bool getOutput() const;
        virtual void run();
        void addSuccessor(Gate* successor);
        void display() const;

    private:

        bool m_notified;
        bool m_output;
        const char* m_name;
        std::vector<Gate*> m_successors;
        virtual bool evaluateOutput() const = 0;
        void addAncestor(Gate* ancestor);
        void notify();
        void update();

    protected:

        std::vector<Gate*> m_ancestors;

};

#endif

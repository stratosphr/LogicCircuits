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
        void notify();

    private:

        bool m_notified;
        const char* m_name;
        virtual bool evaluateOutput() const = 0;
        void addAncestor(Gate* ancestor);
        void update();

    protected:

        bool m_output;
        std::vector<Gate*> m_ancestors;
        std::vector<Gate*> m_successors;

};

#endif

#ifndef GATE_H
#define GATE_H

#include <vector>
#include "thread.h"

class Gate: public Thread{

    public:

        Gate(const char* name = "gate", bool defaultOutput = false);
        bool getOutput() const;
        const char* getName() const;
        std::vector<Gate*> getAncestors() const;
        std::vector<Gate*> getSuccessors() const;
        virtual void run();
        void addSuccessor(Gate* successor);
        void display(unsigned int indentation = 0) const;
        void update();
        void setName(const char* name);
        void setOutputFunction(bool (*outputFunction)(std::vector<bool> ancestorOutputs));

    private:

        bool m_output;
        bool (*m_outputFunction)(std::vector<bool> ancestorOutputs);
        const char* m_name;
        std::vector<Gate*> m_ancestors;
        std::vector<Gate*> m_successors;
        void addAncestor(Gate* ancestor);

};

#endif

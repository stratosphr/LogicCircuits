#ifndef GATE_H
#define GATE_H

#include <vector>

class Gate{

    public:

        Gate(const char* name = "gate");
        const char* getName() const;
        std::vector<Gate*> getAncestors() const;
        std::vector<Gate*> getSuccessors() const;
        void addSuccessor(Gate* successor);
        void display(unsigned int indentation = 0) const;
        void setName(const char* name);

    private:

        const char* m_name;
        std::vector<Gate*> m_ancestors;
        std::vector<Gate*> m_successors;
        void addAncestor(Gate* ancestor);

};

#endif

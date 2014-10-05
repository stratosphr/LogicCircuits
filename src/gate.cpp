#include <iostream>
#include "gate.h"

Gate::Gate(const char* name):
    m_name(name)
{
}

const char* Gate::getName() const{
    return m_name;
}

std::vector<Gate*> Gate::getAncestors() const{
    return m_ancestors;
}

std::vector<Gate*> Gate::getSuccessors() const{
    return m_successors;
}

void Gate::addAncestor(Gate* ancestor){
    m_ancestors.push_back(ancestor);
}

void Gate::addSuccessor(Gate* successor){
    successor->addAncestor(this);
    m_successors.push_back(successor);
}

void Gate::display(unsigned int indentation) const{
    std::cout << m_name << std::endl;
    for(unsigned int i=0; i<m_successors.size(); i++){
        for(unsigned int j=0; j<indentation; j++){
            std::cout << "    ";
        }
        std::cout << "--> ";
        m_successors[i]->display(indentation + 1);
    }
}

void Gate::setName(const char* name){
    m_name = name;
}

#include <iostream>
#include "gate.h"

Gate::Gate(const char* name, const bool defaultOutput):
    Thread(),
    m_notified(false),
    m_name(name),
    m_output(defaultOutput)
{
    start();
}

bool Gate::getOutput() const{
    return m_output;
}

void Gate::run(){
    while(true){
        while(!m_notified){
        }
        m_notified = false;
        update();
    }
}

void Gate::addSuccessor(Gate* successor){
    successor->addAncestor(this);
    m_successors.push_back(successor);
    successor->notify();
}

void Gate::display() const{
    std::cout << m_name << "[" << m_output << "]" << std::endl;
}

void Gate::update(){
    bool previousOutput = m_output;
    m_output = evaluateOutput();
    if(m_output != previousOutput){
        for(unsigned int i=0; i<m_successors.size(); i++){
            m_successors[i]->notify();
        }
    }
}

void Gate::notify(){
    m_notified = true;
}

void Gate::addAncestor(Gate* ancestor){
    m_ancestors.push_back(ancestor);
}

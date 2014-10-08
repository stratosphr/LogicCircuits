#include <iostream>
#include "gate.h"

Gate::Gate(const char* name, const bool defaultOutput):
    Thread(),
    m_notified(false),
    m_output(defaultOutput),
    m_name(name)
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
        std::cout << m_name << " notified !" << std::endl;
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
    std::cout << previousOutput << "->";
    m_output = evaluateOutput();
    std::cout << m_output << std::endl;
    if(m_output != previousOutput){
        for(unsigned int i=0; i<m_successors.size(); i++){
            m_successors[i]->notify();
        }
    }
    display();
}

void Gate::notify(){
    m_notified = true;
}

void Gate::addAncestor(Gate* ancestor){
    m_ancestors.push_back(ancestor);
}

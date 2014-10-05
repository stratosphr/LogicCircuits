#include <iostream>
#include "gate.h"

Gate::Gate(const char* name, bool defaultOutput):
    m_output(defaultOutput),
    m_outputFunction(NULL),
    m_name(name)
{
}

bool Gate::getOutput() const{
    return m_output;
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
    successor->update();
    m_successors.push_back(successor);
}

void Gate::display(unsigned int indentation) const{
    std::cout << m_name << "[" << m_output << "]" << std::endl;
    for(unsigned int i=0; i<m_successors.size(); i++){
        for(unsigned int j=0; j<indentation; j++){
            std::cout << "    ";
        }
        std::cout << "--> ";
        m_successors[i]->display(indentation + 1);
    }
}

void Gate::update(){
    if(m_outputFunction != NULL){
        std::vector<bool> ancestorOutputs;
        for(unsigned int i=0; i<m_ancestors.size(); i++){
            ancestorOutputs.push_back(m_ancestors[i]->getOutput());
        }
        m_output = m_outputFunction(ancestorOutputs);
    }
}

void Gate::setName(const char* name){
    m_name = name;
}

void Gate::setOutputFunction(bool (*outputFunction)(std::vector<bool> ancestorOutputs)){
    m_outputFunction = outputFunction;
}

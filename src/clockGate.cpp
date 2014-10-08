#include "clockGate.h"

ClockGate::ClockGate(const char* name, const bool startOutput, double frequency):
    Gate(name, startOutput),
    m_frequency(frequency)
{
}

void ClockGate::run(){
    while(true){
        std::this_thread::sleep_for(std::chrono::duration<double>(1.0/m_frequency));
        update();
        yield();
    }
}

void ClockGate::update(){
    m_output = !m_output;
    for(unsigned int i=0; i<m_successors.size(); i++){
        m_successors[i]->notify();
    }
}

bool ClockGate::evaluateOutput() const{
    return m_output;
}

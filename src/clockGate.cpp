#include <chrono>
#include <iostream>
#include "clockGate.h"

ClockGate::ClockGate(const char* name, double frequency):
    Gate(name, false),
    m_frequency(frequency)
{
    setOutputFunction(ClockGate::clockFunction);
}

void ClockGate::run(){
    while(true){
        std::this_thread::sleep_for(std::chrono::duration<double>(1.0/m_frequency));
        setOutput(!getOutput());
    }
}

void ClockGate::setFrequency(double frequency){
    m_frequency = frequency;
}

bool ClockGate::clockFunction(std::vector<bool> ancestorOutputs){
    (void) ancestorOutputs; // Suppress compiler warnings
    return false;
}

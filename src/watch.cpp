#include "watch.h"

Watch::Watch(Gate* gateToWatch):
    Thread(),
    m_gateToWatch(gateToWatch)
{
    start();
}

void Watch::run(){
    while(true){
        m_gateToWatch->display();
        yield();
    }
}

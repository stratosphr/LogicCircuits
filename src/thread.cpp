#include "thread.h"

Thread::Thread(){
}

void Thread::join(){
    m_thread.join();
}

void Thread::start(){
    m_thread = std::thread(&Thread::run, this);
}

void Thread::yield(){
    std::this_thread::yield();
}

#ifndef THREAD_H
#define THREAD_H

#include <condition_variable>
#include <mutex>
#include <thread>

class Thread{

    public:

        Thread();
        void join();
        void start();
        void yield();
        virtual void run() = 0;

    private:

        std::thread m_thread;

};

#endif

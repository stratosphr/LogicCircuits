#ifndef THREAD_H
#define THREAD_H

#include <thread>

class Thread{

    public:

        Thread();
        virtual void run() = 0;
        void join();
        void start();

    private:
        std::thread m_thread;

};

#endif

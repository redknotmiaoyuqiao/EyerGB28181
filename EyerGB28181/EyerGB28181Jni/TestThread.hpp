#ifndef EYERGB28181_TESTTHREAD_HPP
#define EYERGB28181_TESTTHREAD_HPP

#include "EyerCore/EyerCore.hpp"
#include "EyerJNI/EyerJNI.hpp"

namespace Eyer
{
    class TestThread : public EyerThread {
    private:
        jobject jo = nullptr;
    public:
        TestThread(jobject _jo);
        ~TestThread();
    public:
        virtual void Run();
    };
}

#endif //EYERGB28181_TESTTHREAD_HPP

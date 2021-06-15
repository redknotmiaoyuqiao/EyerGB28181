#ifndef EYERGB28181_EYEREVENTLOOPTHREAD_HPP
#define EYERGB28181_EYEREVENTLOOPTHREAD_HPP

#include "EyerThread/EyerThread.hpp"
#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class EyerEventLoopThread : public EyerThread
    {
    public:
        EyerEventLoopThread();
        ~EyerEventLoopThread();
        virtual void Run();
    };
}

#endif //EYERGB28181_EYEREVENTLOOPTHREAD_HPP

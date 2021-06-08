#ifndef EYERGB28181_EYEREVENTLOOPTHREAD_HPP
#define EYERGB28181_EYEREVENTLOOPTHREAD_HPP

#include "EyerThread/EyerThread.hpp"

namespace Eyer
{
    class EyerEventLoopThread : public EyerThread
    {
    public:
        virtual void Run();
    };
}

#endif //EYERGB28181_EYEREVENTLOOPTHREAD_HPP

#ifndef EYERLIB_SIPEVENTTHREAD_HPP
#define EYERLIB_SIPEVENTTHREAD_HPP

#include "EyerThread/EyerThread.hpp"
#include "SIPEventQueue.hpp"

namespace Eyer
{
    class SIPServerContext;

    class SIPEventThread : public EyerThread{
    public:
        SIPEventThread(SIPServerContext * _context);
        ~SIPEventThread();

        virtual void Run();

    private:
        SIPServerContext * context = nullptr;
    };
}

#endif //EYERLIB_SIPEVENTTHREAD_HPP

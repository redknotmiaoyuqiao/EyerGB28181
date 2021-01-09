#ifndef EYERLIB_SIPEVENTTHREAD_HPP
#define EYERLIB_SIPEVENTTHREAD_HPP

#include "EyerThread/EyerThread.hpp"
#include "GBEventQueue.hpp"

namespace Eyer
{
    class GBServerContext;

    class SIPEventThread : public EyerThread{
    public:
        SIPEventThread(GBServerContext * _context);
        ~SIPEventThread();

        virtual void Run();

    private:
        GBServerContext * context = nullptr;
    };
}

#endif //EYERLIB_SIPEVENTTHREAD_HPP

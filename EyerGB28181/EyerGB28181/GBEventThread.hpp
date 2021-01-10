#ifndef EYERLIB_SIPEVENTTHREAD_HPP
#define EYERLIB_SIPEVENTTHREAD_HPP

#include "EyerThread/EyerThread.hpp"
#include "GBEventQueue.hpp"

namespace Eyer
{
    class GBServerContext;

    class GBEventThread : public EyerThread{
    public:
        GBEventThread(GBServerContext * _context);
        ~GBEventThread();

        virtual void Run();

    private:
        GBServerContext * context = nullptr;
    };
}

#endif //EYERLIB_SIPEVENTTHREAD_HPP

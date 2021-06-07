#ifndef EYERLIB_SIPSERVERMAINTHREAD_HPP
#define EYERLIB_SIPSERVERMAINTHREAD_HPP

#include "EyerThread/EyerThread.hpp"
#include "eXosipHeader.hpp"
#include "GBServerContext.hpp"

namespace Eyer
{
    class GBServerMainThread : public EyerThread {
    public:
        GBServerMainThread(int _port, GBServerContext * _context);
        ~GBServerMainThread();

        virtual void Run();

    private:
        int port = 5060;
        GBServerContext * context = nullptr;

        int PrintJe(eXosip_event_t * je);

        int EventLoop           (struct eXosip_t * excontext);
        int ANSWEREDProcess     (eXosip_event_t * je, struct eXosip_t * excontext);
    };
}

#endif //EYERLIB_SIPSERVERMAINTHREAD_HPP

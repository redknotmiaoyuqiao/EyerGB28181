#ifndef EYERLIB_SIPSERVERMAINTHREAD_HPP
#define EYERLIB_SIPSERVERMAINTHREAD_HPP

#include "EyerThread/EyerThread.hpp"
#include "eXosipHeader.hpp"
#include "SIPServerContext.hpp"

namespace Eyer
{
    class SIPServerMainThread : public EyerThread {
    public:
        SIPServerMainThread(int _port, SIPServerContext * _context);
        ~SIPServerMainThread();

        virtual void Run();

    private:
        int port = 5060;
        SIPServerContext * context = nullptr;

        int PrintJe(eXosip_event_t * je);

        int EventLoop           (eXosip_event_t * je, struct eXosip_t * excontext);
        int ANSWEREDProcess     (eXosip_event_t * je, struct eXosip_t * excontext);
    };
}

#endif //EYERLIB_SIPSERVERMAINTHREAD_HPP

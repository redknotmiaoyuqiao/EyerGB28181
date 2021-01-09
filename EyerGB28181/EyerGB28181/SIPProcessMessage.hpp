#ifndef EYERLIB_SIPPROCESSMESSAGE_HPP
#define EYERLIB_SIPPROCESSMESSAGE_HPP

#include "SIPProcess.hpp"

namespace Eyer
{
    class SIPProcessMessage : public SIPProcess {
    public:
        virtual int Process(GBServerContext * context, struct eXosip_t * excontext, eXosip_event_t * je);
    };
}

#endif //EYERLIB_SIPPROCESSMESSAGE_HPP

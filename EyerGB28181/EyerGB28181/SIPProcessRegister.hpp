#ifndef EYERLIB_SIPPROCESSREGISTER_HPP
#define EYERLIB_SIPPROCESSREGISTER_HPP

#include "SIPProcess.hpp"
#include "GBServerContext.hpp"

namespace Eyer
{
    class SIPProcessRegister : public SIPProcess {
    public:
        virtual int Process(GBServerContext * context, struct eXosip_t * excontext, eXosip_event_t * je);
    };
}

#endif //EYERLIB_SIPPROCESSREGISTER_HPP

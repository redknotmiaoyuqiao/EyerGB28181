#ifndef EYERLIB_SIPPROCESSREGISTER_HPP
#define EYERLIB_SIPPROCESSREGISTER_HPP

#include "SIPProcess.hpp"
#include "SIPServerContext.hpp"

namespace Eyer
{
    class SIPProcessRegister : public SIPProcess {
    public:
        virtual int Process(SIPServerContext * context, struct eXosip_t * excontext, eXosip_event_t * je);
    };
}

#endif //EYERLIB_SIPPROCESSREGISTER_HPP

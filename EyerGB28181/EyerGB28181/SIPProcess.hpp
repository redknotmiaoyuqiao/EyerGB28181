#ifndef EYERLIB_SIPPROCESS_HPP
#define EYERLIB_SIPPROCESS_HPP

#include "eXosipHeader.hpp"
#include "SIPServerContext.hpp"

namespace Eyer
{
    class SIPProcess {
    public:
        virtual int Process(SIPServerContext * context, struct eXosip_t * excontext, eXosip_event_t * je) = 0;
    };
}

#endif //EYERLIB_SIPPROCESS_HPP

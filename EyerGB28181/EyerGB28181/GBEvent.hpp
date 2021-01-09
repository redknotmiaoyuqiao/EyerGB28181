#ifndef EYERLIB_SIPEVENT_HPP
#define EYERLIB_SIPEVENT_HPP

#include "SIPEventType.hpp"
#include "eXosipHeader.hpp"

namespace Eyer
{
    class GBServerContext;
    class GBEvent {
    public:
        GBEvent();
        virtual ~GBEvent();

        virtual SIPEventType GetEventType() = 0;
        virtual int Do(struct eXosip_t * excontext, GBServerContext * context) = 0;

        SIPEventTarget from;
        SIPEventTarget to;
    };
}

#endif //EYERLIB_SIPEVENT_HPP

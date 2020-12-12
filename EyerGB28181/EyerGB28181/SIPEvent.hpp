#ifndef EYERLIB_SIPEVENT_HPP
#define EYERLIB_SIPEVENT_HPP

#include "SIPEventType.hpp"
#include "eXosipHeader.hpp"

namespace Eyer
{
    class SIPServerContext;
    class SIPEvent {
    public:
        SIPEvent();
        virtual ~SIPEvent();

        virtual SIPEventType GetEventType() = 0;
        virtual int Do(struct eXosip_t * excontext, SIPServerContext * context) = 0;

        SIPEventTarget from;
        SIPEventTarget to;
    };
}

#endif //EYERLIB_SIPEVENT_HPP

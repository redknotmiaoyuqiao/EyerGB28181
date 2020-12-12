#ifndef EYERLIB_EVENTUSERREGISTER_HPP
#define EYERLIB_EVENTUSERREGISTER_HPP

#include "SIPEvent.hpp"

namespace Eyer
{
    class EventUserRegister : public SIPEvent{
    public:
        EventUserRegister();
        ~EventUserRegister();

        EventUserRegister(const EventUserRegister & event);
        EventUserRegister & operator = (const EventUserRegister & event);

        virtual SIPEventType GetEventType();

        virtual int Do(struct eXosip_t * excontext, SIPServerContext * context);

    public:
        EyerString deviceId;
    };
}

#endif //EYERLIB_EVENTUSERREGISTER_HPP

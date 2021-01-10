#ifndef EYERLIB_EVENTUSERREGISTER_HPP
#define EYERLIB_EVENTUSERREGISTER_HPP

#include "GBEvent.hpp"

namespace Eyer
{
    class EventUserRegister : public GBEvent{
    public:
        EventUserRegister();
        ~EventUserRegister();

        EventUserRegister(const EventUserRegister & event);
        EventUserRegister & operator = (const EventUserRegister & event);

        virtual GBEventType GetEventType();

        virtual int Do(struct eXosip_t * excontext, GBServerContext * context);

    public:
        EyerString deviceId;
    };
}

#endif //EYERLIB_EVENTUSERREGISTER_HPP

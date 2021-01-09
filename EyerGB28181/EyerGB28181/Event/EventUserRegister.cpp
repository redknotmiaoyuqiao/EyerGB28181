#include "EventUserRegister.hpp"

#include "eXosipHeader.hpp"

namespace Eyer
{
    EventUserRegister::EventUserRegister()
    {
        to = SIPEventTarget::SIPEventTarget_EventThread;
        from = SIPEventTarget::SIPEventTarget_MainThread;
    }

    EventUserRegister::~EventUserRegister()
    {

    }

    SIPEventType EventUserRegister::GetEventType()
    {
        return SIPEventType::USER_REGISTER;
    }

    EventUserRegister::EventUserRegister(const EventUserRegister & event)
    {
        *this = event;
    }

    EventUserRegister & EventUserRegister::operator = (const EventUserRegister & event)
    {
        deviceId = event.deviceId;
        return *this;
    }

    int EventUserRegister::Do(struct eXosip_t * excontext, GBServerContext * context)
    {
        eXosip_lock(excontext);

        eXosip_unlock(excontext);
        return 0;
    }
}
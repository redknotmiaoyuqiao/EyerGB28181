#include "EventDeviceHeart.hpp"

namespace Eyer
{
    EventDeviceHeart::EventDeviceHeart()
    {
        from = SIPEventTarget::SIPEventTarget_MainThread;
        to = SIPEventTarget::SIPEventTarget_EventThread;
    }

    EventDeviceHeart::~EventDeviceHeart()
    {

    }

    EventDeviceHeart::EventDeviceHeart(const EventDeviceHeart & event)
    {
        *this = event;
    }

    EventDeviceHeart & EventDeviceHeart::operator = (const EventDeviceHeart & event)
    {
        deviceId = event.deviceId;
        return *this;
    }

    SIPEventType EventDeviceHeart::GetEventType()
    {
        return SIPEventType::DEVICE_HEART;
    }

    int EventDeviceHeart::Do(struct eXosip_t * excontext, SIPServerContext * context)
    {
        return 0;
    }
}
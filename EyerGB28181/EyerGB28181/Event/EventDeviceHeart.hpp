#ifndef EYERGB28181_EVENTDEVICEHEART_HPP
#define EYERGB28181_EVENTDEVICEHEART_HPP

#include "SIPEvent.hpp"

namespace Eyer
{
    class EventDeviceHeart : public SIPEvent{
    public:
        EventDeviceHeart();
        ~EventDeviceHeart();

        EventDeviceHeart(const EventDeviceHeart & event);
        EventDeviceHeart & operator = (const EventDeviceHeart & event);

        virtual SIPEventType GetEventType();

        virtual int Do(struct eXosip_t * excontext, SIPServerContext * context);

    public:
        EyerString deviceId;
    };
}

#endif //EYERGB28181_EVENTDEVICEHEART_HPP

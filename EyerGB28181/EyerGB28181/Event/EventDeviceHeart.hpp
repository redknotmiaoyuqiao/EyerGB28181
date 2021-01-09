#ifndef EYERGB28181_EVENTDEVICEHEART_HPP
#define EYERGB28181_EVENTDEVICEHEART_HPP

#include "GBEvent.hpp"

namespace Eyer
{
    class EventDeviceHeart : public GBEvent{
    public:
        EventDeviceHeart();
        ~EventDeviceHeart();

        EventDeviceHeart(const EventDeviceHeart & event);
        EventDeviceHeart & operator = (const EventDeviceHeart & event);

        virtual SIPEventType GetEventType();

        virtual int Do(struct eXosip_t * excontext, GBServerContext * context);

    public:
        EyerString deviceId;
    };
}

#endif //EYERGB28181_EVENTDEVICEHEART_HPP

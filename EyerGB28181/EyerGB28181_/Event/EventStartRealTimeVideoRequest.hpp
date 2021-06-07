#ifndef EYERLIB_EVENTSTARTREALTIMEVIDEOREQUEST_HPP
#define EYERLIB_EVENTSTARTREALTIMEVIDEOREQUEST_HPP

#include "Callback/StartStreamCallback.hpp"
#include "GBEvent.hpp"

namespace Eyer
{
    class EventStartRealTimeVideoRequest : public GBEvent{
    public:
        EventStartRealTimeVideoRequest();
        ~EventStartRealTimeVideoRequest();

        EventStartRealTimeVideoRequest(const EventStartRealTimeVideoRequest & event);
        EventStartRealTimeVideoRequest & operator = (const EventStartRealTimeVideoRequest & event);

        virtual GBEventType GetEventType();

        virtual int Do(struct eXosip_t * excontext, GBServerContext * context);

    public:
        EyerString streamServerIp;
        int streamServerPort;
        EyerString deviceId;
        EyerString channelId;
        StartStreamCallback * startStreamCallback = nullptr;
    };
}

#endif //EYERLIB_EVENTSTARTREALTIMEVIDEOREQUEST_HPP

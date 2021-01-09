#ifndef EYERLIB_EVENTSTARTREALTIMEVIDEORESPONSE_HPP
#define EYERLIB_EVENTSTARTREALTIMEVIDEORESPONSE_HPP

#include "GBEvent.hpp"
#include "Callback/ActiveCallback.hpp"

namespace Eyer {
    class EventStartRealTimeVideoResponse : public GBEvent{
    public:
        EventStartRealTimeVideoResponse();
        ~EventStartRealTimeVideoResponse();

        EventStartRealTimeVideoResponse(const EventStartRealTimeVideoResponse & event);
        EventStartRealTimeVideoResponse & operator = (const EventStartRealTimeVideoResponse & event);

        virtual SIPEventType GetEventType();

        virtual int Do(struct eXosip_t * excontext, GBServerContext * context);

    public:
        EyerString callId;
        int status = 200;
    };
}


#endif //EYERLIB_EVENTSTARTREALTIMEVIDEORESPONSE_HPP

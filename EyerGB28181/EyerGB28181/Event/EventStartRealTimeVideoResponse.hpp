#ifndef EYERLIB_EVENTSTARTREALTIMEVIDEORESPONSE_HPP
#define EYERLIB_EVENTSTARTREALTIMEVIDEORESPONSE_HPP

#include "SIPEvent.hpp"
#include "Callback/ActiveCallback.hpp"

namespace Eyer {
    class EventStartRealTimeVideoResponse : public SIPEvent{
    public:
        EventStartRealTimeVideoResponse();
        ~EventStartRealTimeVideoResponse();

        EventStartRealTimeVideoResponse(const EventStartRealTimeVideoResponse & event);
        EventStartRealTimeVideoResponse & operator = (const EventStartRealTimeVideoResponse & event);

        virtual SIPEventType GetEventType();

        virtual int Do(struct eXosip_t * excontext, SIPServerContext * context);

    public:
        EyerString callId;
        int status = 200;
    };
}


#endif //EYERLIB_EVENTSTARTREALTIMEVIDEORESPONSE_HPP

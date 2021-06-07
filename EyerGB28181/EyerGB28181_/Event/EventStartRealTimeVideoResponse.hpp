#ifndef EYERLIB_EVENTSTARTREALTIMEVIDEORESPONSE_HPP
#define EYERLIB_EVENTSTARTREALTIMEVIDEORESPONSE_HPP

#include "GBPlaybackSession.hpp"
#include "GBEvent.hpp"
#include "Callback/ActiveCallback.hpp"

namespace Eyer {
    class EventStartRealTimeVideoResponse : public GBEvent{
    public:
        EventStartRealTimeVideoResponse();
        ~EventStartRealTimeVideoResponse();

        EventStartRealTimeVideoResponse(const EventStartRealTimeVideoResponse & event);
        EventStartRealTimeVideoResponse & operator = (const EventStartRealTimeVideoResponse & event);

        virtual GBEventType GetEventType();

        virtual int Do(struct eXosip_t * excontext, GBServerContext * context);

    public:
        EyerString callId;
        int status = 200;

        GBPlaybackSession gbPlaybackSession;
    };
}


#endif //EYERLIB_EVENTSTARTREALTIMEVIDEORESPONSE_HPP

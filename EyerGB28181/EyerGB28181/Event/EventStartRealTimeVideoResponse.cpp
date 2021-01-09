#include "EventStartRealTimeVideoResponse.hpp"

namespace Eyer
{
    EventStartRealTimeVideoResponse::EventStartRealTimeVideoResponse()
    {
        to = SIPEventTarget::SIPEventTarget_EventThread;
        from = SIPEventTarget::SIPEventTarget_MainThread;
    }

    EventStartRealTimeVideoResponse::~EventStartRealTimeVideoResponse()
    {

    }

    EventStartRealTimeVideoResponse::EventStartRealTimeVideoResponse(const EventStartRealTimeVideoResponse & event)
    {
        *this = event;
    }

    EventStartRealTimeVideoResponse & EventStartRealTimeVideoResponse::operator = (const EventStartRealTimeVideoResponse & event)
    {
        to                      = event.to;
        from                    = event.from;
        return *this;
    }

    SIPEventType EventStartRealTimeVideoResponse::GetEventType()
    {
        return SIPEventType::REALTIME_RESPONSE;
    }

    int EventStartRealTimeVideoResponse::Do(struct eXosip_t * excontext, GBServerContext * context)
    {
        return 0;
    }
}
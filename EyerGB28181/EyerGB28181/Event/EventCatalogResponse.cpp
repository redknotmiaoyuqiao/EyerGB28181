#include "EventCatalogResponse.hpp"

namespace Eyer
{
    EventCatalogResponse::EventCatalogResponse()
    {
        from    = SIPEventTarget::SIPEventTarget_MainThread;
        to      = SIPEventTarget::SIPEventTarget_EventThread;
    }

    EventCatalogResponse::~EventCatalogResponse()
    {

    }

    EventCatalogResponse::EventCatalogResponse(const EventCatalogResponse & event)
    {
        *this = event;
    }

    EventCatalogResponse & EventCatalogResponse::operator = (const EventCatalogResponse & event)
    {
        cataDeviceList  = event.cataDeviceList;
        callId          = event.callId;
        return *this;
    }

    SIPEventType EventCatalogResponse::GetEventType()
    {
        return SIPEventType::CATA_RESPONSE;
    }

    int EventCatalogResponse::Do(struct eXosip_t * excontext, SIPServerContext * context)
    {
        return 0;
    }
}
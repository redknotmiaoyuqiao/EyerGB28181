#include "EventCatalogRequest.hpp"
#include "EventStartRealTimeVideoRequest.hpp"
#include "SIPServerContext.hpp"
#include "eXosipHeader.hpp"

namespace Eyer
{
    EventCatalogRequest::EventCatalogRequest()
    {
        to      = SIPEventTarget::SIPEventTarget_MainThread;
        from    = SIPEventTarget::SIPEventTarget_EventThread;
    }

    EventCatalogRequest::~EventCatalogRequest()
    {

    }

    EventCatalogRequest::EventCatalogRequest(const EventCatalogRequest & event)
    {
        *this = event;
    }

    EventCatalogRequest & EventCatalogRequest::operator = (const EventCatalogRequest & event)
    {
        to                  = event.to;
        from                = event.from;

        deviceId            = event.deviceId;
        catalogCallback     = event.catalogCallback;

        return *this;
    }

    SIPEventType EventCatalogRequest::GetEventType()
    {
        return SIPEventType::CATA_REQUEST;
    }

    int EventCatalogRequest::Do(struct eXosip_t * excontext, SIPServerContext * context)
    {
        GBDevice device;
        int ret = context->deviceManager.FindDevice(device, deviceId);
        if(ret){
            return -1;
        }

        EyerLog("We Find Device: %s\n", device.GetDeviceID().str);

        return 0;
    }
}
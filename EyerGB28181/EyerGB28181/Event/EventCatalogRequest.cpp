#include "EventCatalogRequest.hpp"
#include "EventStartRealTimeVideoRequest.hpp"
#include "SIPServerContext.hpp"
#include "eXosipHeader.hpp"
#include "EyerCore/EyerCore.hpp"

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
            EyerLog("Do Not Find Device %s\n", deviceId.str);
            return -1;
        }

        EyerString callId = EyerRand::RandNumberStr(4);
        context->activeCallbackList.PutCallback(catalogCallback, callId);

        // EyerLog("Call Id: %s\n", callId.str);

        // Catalog
        EyerString to = EyerString("sip:") + device.GetDeviceID() + "@" + device.GetIP() + ":" + device.GetPort();
        char * from = (char *)"sip:34020000002000000001@34020000";

        osip_message_t * msg = NULL;
        eXosip_message_build_request(excontext, &msg, "MESSAGE", to.str, from, NULL);

        char queryContent[2048];
        sprintf(queryContent,
                "<?xml version=\"1.0\"?>"
                "<Query>"
                "<CmdType>Catalog</CmdType>"
                "<SN>%s</SN>"
                "<DeviceID>34020000001320000001</DeviceID>"
                "</Query>",
                callId.str
                );

        osip_message_set_contact(msg, "sip:34020000002000000001@123.57.50.178:5060");
        osip_message_set_body (msg, queryContent, strlen(queryContent));
        osip_message_set_content_type (msg, "Application/MANSCDP+xml");
        ret = eXosip_message_send_request(excontext, msg);

        return 0;
    }
}
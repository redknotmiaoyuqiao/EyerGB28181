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

        // EyerLog("AAA We Find Device: %s\n", device.GetDeviceID().str);

        // Catalog
        EyerString to = EyerString("sip:") + device.GetDeviceID() + "@" + device.GetIP() + ":" + device.GetPort();
        char * from = (char *)"sip:34020000002000000001@34020000";

        osip_message_t * msg = NULL;
        eXosip_message_build_request(excontext, &msg, "MESSAGE", to.str, from, NULL);
        char * queryContent = "<?xml version=\"1.0\"?>\r\n<Query><CmdType>Catalog</CmdType><SN>4</SN><DeviceID>34020000001320000001</DeviceID></Query>";

        osip_message_set_contact(msg, "sip:34020000002000000001@192.168.2.102:5060");
        osip_message_set_body (msg, queryContent, strlen(queryContent));
        osip_message_set_content_type (msg, "Application/MANSCDP+xml");
        eXosip_message_send_request(excontext, msg);

        char * msgStr = nullptr;
        size_t msgLen = 0;
        osip_message_to_str(msg, &msgStr, &msgLen);

        // EyerLog("Msg: %s\n", msgStr);

        // EyerLog("BBB We Find Device: %s\n", device.GetDeviceID().str);

        return 0;
    }
}
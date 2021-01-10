#include "EventCatalogRequest.hpp"
#include "EventStartRealTimeVideoRequest.hpp"
#include "GBServerContext.hpp"
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

    GBEventType EventCatalogRequest::GetEventType()
    {
        return GBEventType::CATA_REQUEST;
    }

    int EventCatalogRequest::Do(struct eXosip_t * excontext, GBServerContext * context)
    {
        EyerINFO("===============Catalog Request===============\n");

        GBDevice device;
        int ret = context->deviceManager.FindDevice(device, deviceId);
        if(ret){
            EyerERROR("Catalog Do Not Find Device %s\n", deviceId.str);
            return -1;
        }

        EyerString callId = EyerRand::RandNumberStr(4);
        context->activeCallbackList.PutCallback(catalogCallback, callId);

        if(device.GetDeviceID().IsEmpty()){
            EyerERROR("Catalog GetDeviceID Fail\n");
            return -2;
        }
        if(device.GetIP().IsEmpty()){
            EyerERROR("Catalog GetIP Fail\n");
            return -2;
        }
        if(device.GetPort().IsEmpty()){
            EyerERROR("Catalog GetPort Fail\n");
            return -2;
        }

        EyerINFO("Catalog device:: device ID: %s\n", device.GetDeviceID().str);
        EyerINFO("Catalog device:: IP: %s\n", device.GetIP().str);
        EyerINFO("Catalog device:: PORT: %s\n", device.GetPort().str);

        EyerString to = EyerString("sip:") + device.GetDeviceID() + "@" + device.GetIP() + ":" + device.GetPort();
        EyerString from = EyerString("sip:") + context->serverId + "@" + context->serverRealm;

        osip_message_t * msg = NULL;
        eXosip_message_build_request(excontext, &msg, "MESSAGE", to.str, from.str, NULL);
        if(msg == NULL){
            EyerERROR("Catalog eXosip_message_build_request Fail\n");
            return -3;
        }

        char queryContent[2048];
        sprintf(queryContent,
                "<?xml version=\"1.0\"?>"
                "<Query>"
                "<CmdType>Catalog</CmdType>"
                "<SN>%s</SN>"
                "<DeviceID>%s</DeviceID>"
                "</Query>",
                callId.str,
                device.GetDeviceID().str
                );

        // osip_message_set_contact(msg, "sip:34020000002000000001@123.57.50.178:5060");
        osip_message_set_body (msg, queryContent, strlen(queryContent));
        osip_message_set_content_type (msg, "Application/MANSCDP+xml");

        char * dest = nullptr;
        size_t message_length = 0;
        osip_message_to_str(msg, &dest, &message_length);
        EyerINFO("Catalog SIP Message: %s\n", dest);
        osip_free(dest);

        eXosip_lock(excontext);
        ret = eXosip_message_send_request(excontext, msg);
        eXosip_unlock(excontext);

        EyerINFO("Catalog eXosip_message_send_request: %d\n", ret);

        return 0;
    }
}
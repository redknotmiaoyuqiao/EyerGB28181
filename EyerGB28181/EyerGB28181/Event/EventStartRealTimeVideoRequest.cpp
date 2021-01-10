#include "EventStartRealTimeVideoRequest.hpp"
#include "GBServerContext.hpp"
#include "eXosipHeader.hpp"

namespace Eyer
{
    EventStartRealTimeVideoRequest::EventStartRealTimeVideoRequest()
    {
        to = SIPEventTarget::SIPEventTarget_MainThread;
        from = SIPEventTarget::SIPEventTarget_EventThread;
    }

    EventStartRealTimeVideoRequest::~EventStartRealTimeVideoRequest()
    {

    }

    EventStartRealTimeVideoRequest::EventStartRealTimeVideoRequest(const EventStartRealTimeVideoRequest & event)
    {
        *this = event;
    }

    EventStartRealTimeVideoRequest & EventStartRealTimeVideoRequest::operator = (const EventStartRealTimeVideoRequest & event)
    {
        to                      = event.to;
        from                    = event.from;

        streamServerIp          = event.streamServerIp;
        streamServerPort        = event.streamServerPort;
        deviceId                = event.deviceId;
        channelId               = event.channelId;
        startStreamCallback     = event.startStreamCallback;

        return *this;
    }

    GBEventType EventStartRealTimeVideoRequest::GetEventType()
    {
        return GBEventType::REALTIME_REQUEST;
    }

    int EventStartRealTimeVideoRequest::Do(struct eXosip_t * excontext, GBServerContext * context)
    {
        EyerINFO("===============StartRealTimeVideo Request===============\n");

        GBDevice device;
        int ret = context->deviceManager.FindDevice(device, deviceId);
        if(ret){
            EyerERROR("StartRealTimeVideo Do Not Find Device %s\n", deviceId.str);
            return -1;
        }

        if(device.GetDeviceID().IsEmpty()){
            EyerERROR("StartRealTimeVideo GetDeviceID Fail\n");
            return -2;
        }
        if(device.GetIP().IsEmpty()){
            EyerERROR("StartRealTimeVideo GetIP Fail\n");
            return -2;
        }
        if(device.GetPort().IsEmpty()){
            EyerERROR("StartRealTimeVideo GetPort Fail\n");
            return -2;
        }

        EyerString to = EyerString("sip:") + device.GetDeviceID() + "@" + device.GetIP() + ":" + device.GetPort();
        EyerString from = EyerString("sip:") + context->serverId + "@" + context->serverRealm;
        EyerString subject = EyerString() + device.GetDeviceID() + ":0," + context->serverId + ":0";

        osip_message_t *invite = NULL;
        ret = eXosip_call_build_initial_invite(excontext, &invite, to.str, from.str, to.str, subject.str);

        if(invite == NULL){
            EyerERROR("StartRealTimeVideo eXosip_message_build_request Fail\n");
            return -3;
        }

        EyerString sses = EyerRand::RandNumberStr(6);

        char body[500];
        int bodyLen = snprintf(body, 500,
                               "v=0\r\n"
                               "o=%s 0 0 IN IP4 %s\r\n"
                               "s=Play\r\n"
                               "c=IN IP4 %s\r\n"
                               "t=0 0\r\n"
                               "m=video %d RTP/AVP 96 97 98\r\n"
                               "a=rtpmap:96 PS/90000\r\n"
                               "a=rtpmap:97 MPEG4/90000\r\n"
                               "a=rtpmap:98 H264/90000\r\n"
                               "a=recvonly\r\n"
                               "y=%s\r\n",
                               context->serverId.str,
                               streamServerIp.str,
                               streamServerIp.str,
                               streamServerPort, sses.str);

        EyerLog("sses: %s\n", sses.str);

        osip_message_set_body(invite, body, bodyLen);
        osip_message_set_content_type(invite, "APPLICATION/SDP");

        char * osip_str = nullptr;
        size_t osip_str_length = 0;
        osip_message_to_str(invite, &osip_str, &osip_str_length);
        EyerLog("StartRealTimeVideo SIP Message: %s\n", osip_str);
        osip_free(osip_str);

        EyerString callId = invite->call_id->number;
        context->activeCallbackList.PutCallback(startStreamCallback, callId);

        eXosip_lock(excontext);
        int call_id = eXosip_call_send_initial_invite(excontext, invite);
        eXosip_unlock(excontext);

        EyerINFO("StartRealTimeVideo eXosip_call_send_initial_invite: %d\n", call_id);

        return 0;
    }
}
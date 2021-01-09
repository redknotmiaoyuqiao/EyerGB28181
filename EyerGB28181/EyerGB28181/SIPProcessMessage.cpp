#include "SIPProcessMessage.hpp"

#include <string>
#include <EyerSIP/EyerSIPMessgae.hpp>
#include "Event/EventCatalogResponse.hpp"
#include "Event/EventDeviceHeart.hpp"

#include "EyerXMLMessage/EyerXMLMessage.hpp"

namespace Eyer
{
    int SIPProcessMessage::Process(GBServerContext * context, struct eXosip_t * excontext, eXosip_event_t * je)
    {
        // 验证是否已经注册
        EyerSIPMessgae sipMessgae(je->request);
        EyerString deviceID = sipMessgae.GetDeviceId();

        EyerString body = sipMessgae.GetBody();

        EyerXMLMsg xmlMsg;
        xmlMsg.Parse(body);

        EyerLog("%s\n", body.str);

        if(xmlMsg.GetCMDType() == "Keepalive"){
            // 发送 心跳 消息
            EventDeviceHeart * deviceHeart = new EventDeviceHeart();
            deviceHeart->deviceId = deviceID;
            context->eventQueue.PutEvent(deviceHeart);
        }

        if(xmlMsg.GetCMDType() == "Catalog"){
            EyerXMLCatalog catalog;
            catalog.Parse(body);
            EventCatalogResponse * catalogResponse = new EventCatalogResponse();
            catalogResponse->cataDeviceList     = catalog.deviceList;
            catalogResponse->callId             = catalog.SN;
            context->eventQueue.PutEvent(catalogResponse);
        }

        GBDevice device;
        int ret = context->deviceManager.FindDevice(device, deviceID);
        if(ret){
            // 尚未注册
            EyerLog("No Register\n");
            osip_message_t * answer = NULL;
            eXosip_message_build_answer (excontext, je->tid, 407, &answer);
            eXosip_message_send_answer (excontext, je->tid, 407, answer);
        }
        else{
            // 已经注册
            EyerLog("Already Register\n");
            osip_message_t * answer = NULL;
            eXosip_message_build_answer (excontext, je->tid, 200, &answer);
            eXosip_message_send_answer (excontext, je->tid, 200, answer);
        }

        return 0;
    }
}
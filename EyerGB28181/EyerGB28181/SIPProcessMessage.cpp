#include "SIPProcessMessage.hpp"

#include <string>
#include <EyerSIP/EyerSIPMessgae.hpp>

#include <tinyxml2.h>

namespace Eyer
{
    int SIPProcessMessage::Process(SIPServerContext * context, struct eXosip_t * excontext, eXosip_event_t * je)
    {
        // 验证是否已经注册
        EyerSIPMessgae sipMessgae(je->request);
        EyerString deviceID = sipMessgae.GetDeviceId();

        EyerString body = sipMessgae.GetBody();
        EyerLog("Body: %s\n", body.str);

        tinyxml2::XMLDocument bodyDoc;
        bodyDoc.Parse(body.str, strlen(body.str));
        tinyxml2::XMLElement * root = bodyDoc.RootElement();
        EyerLog("Root: %s\n", root->Name());
        

        GBDevice device;
        int ret = context->deviceManager.FindDevice(device, deviceID);
        if(ret){
            // 尚未注册
            // EyerLog("No Register\n");
            osip_message_t * answer = NULL;
            eXosip_message_build_answer (excontext, je->tid, 407, &answer);
            eXosip_message_send_answer (excontext, je->tid, 407, answer);
        }
        else{
            // 已经注册
            // EyerLog("Already Register\n");
            osip_message_t * answer = NULL;
            eXosip_message_build_answer (excontext, je->tid, 200, &answer);
            eXosip_message_send_answer (excontext, je->tid, 200, answer);
        }

        return 0;
    }
}
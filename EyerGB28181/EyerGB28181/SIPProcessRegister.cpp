#include "SIPProcessRegister.hpp"

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <sstream>

#include "EyerSIP/EyerSIP.hpp"

#include "Event/EventUserRegister.hpp"

#define NONCE "9bd055"
#define ALGORITHTHM "MD5"

namespace Eyer
{
    int SIPProcessRegister::Process(SIPServerContext * context, struct eXosip_t * excontext, eXosip_event_t * je)
    {
        osip_authorization_t * auth = NULL;
        osip_message_get_authorization(je->request, 0, &auth);

        if (NULL == auth) {
            // 401
            osip_message_t * answer = NULL;
            int result = eXosip_message_build_answer(excontext, je->tid, 401, &answer);

            std::stringstream stream;
            std::string nonce = NONCE;
            std::string algorithm = ALGORITHTHM;
            stream << "Digest realm=\"" << "abc"
                   << "\",nonce=\"" << nonce
                   << "\",algorithm=" << algorithm;
            osip_message_set_header(answer, "WWW-Authenticate", stream.str().c_str());

            eXosip_lock(excontext);
            eXosip_message_send_answer(excontext, je->tid, 401, answer);
            eXosip_unlock(excontext);
        }
        else{
            EyerSIPMessgae sipMessgaeRequest(je->request);
            EyerString deviceID         = sipMessgaeRequest.GetDeviceId();

            osip_message_t * asw_register = nullptr;
            int ret = eXosip_message_build_answer (excontext, je->tid, 200, &asw_register);

            // TODO 验证信息 这里直接返回 200
            EyerSIPMessgae sipMessgae(asw_register);
            EyerString deviceIp         = sipMessgae.GetIp();
            EyerString devicePort       = sipMessgae.GetPort();

            /*
            EyerLog("deviceId: %s\n", deviceID.str);
            EyerLog("deviceIp: %s\n", deviceIp.str);
            EyerLog("devicePort: %s\n", devicePort.str);
            */

            GBDevice device;
            ret = context->deviceManager.FindDevice(device, deviceID);
            if(ret){
                // 新用户
                EyerLog("New User Register\n");
                context->deviceManager.Register(deviceID, deviceIp, devicePort);
                // 发送 消息
                EventUserRegister * eventUserRegister = new EventUserRegister();
                eventUserRegister->deviceId = deviceID;
                context->eventQueue.PutEvent(eventUserRegister);
            }
            else{
                // 重复注册
                EyerLog("User Register Again\n");
            }

            osip_message_t * answer = NULL;
            eXosip_message_build_answer (excontext, je->tid, 200, &answer);
            eXosip_message_send_answer (excontext, je->tid, 200, answer);


            /*
             */

            /*
            // Query Device Info
            EyerString to = EyerString("sip:") + deviceID + "@" + deviceIp + ":" + devicePort;
            char * from = (char *)"sip:34020000002000000001@34020000";

            osip_message_t * msg = NULL;
            eXosip_message_build_request(excontext, &msg, "MESSAGE", to.str, from, NULL);
            char * queryContent = "<?xml version=\"1.0\"?>\r\n<Query><CmdType>Catalog</CmdType><SN>4</SN><DeviceID>34020000001320000001</DeviceID></Query>";

            osip_message_set_contact(msg, "sip:34020000002000000001@192.168.2.106:5060");
            osip_message_set_body (msg, queryContent, strlen(queryContent));
            osip_message_set_content_type (msg, "Application/MANSCDP+xml");
            eXosip_message_send_request(excontext, msg);
            */
        }
        return 0;
    }
}
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
    int SIPProcessRegister::Process(GBServerContext * context, struct eXosip_t * excontext, eXosip_event_t * je)
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

            // asw_register 需要手动释放
            osip_message_t * asw_register = nullptr;
            int ret = eXosip_message_build_answer (excontext, je->tid, 200, &asw_register);

            // TODO 验证信息 这里直接返回 200
            EyerSIPMessgae sipMessgae(asw_register);
            EyerString deviceIp         = sipMessgae.GetIp();
            EyerString devicePort       = sipMessgae.GetPort();

            osip_message_free(asw_register);

            GBDevice device;
            ret = context->deviceManager.FindDevice(device, deviceID);
            if(ret){
                // 新用户
                // EyerLog("New User Register\n");
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
        }
        return 0;
    }
}
#include "EyerSIPMessgae.hpp"
#include "EyerSIPMessgaePrivate.hpp"
#include "EyerSIPFromPrivate.hpp"
#include "EyerSIPCallIDPrivate.hpp"
#include "EyerSIPCseqPrivate.hpp"
#include "EyerSIPContactPrivate.hpp"
#include "EyerSIPUriPrivate.hpp"

namespace Eyer
{
    EyerSIPMessgae::EyerSIPMessgae()
    {
        parser_init();
        impl = new EyerSIPMessgaePrivate();
        osip_message_init(&impl->sip);
    }

    EyerSIPMessgae::EyerSIPMessgae(osip_message_t * sip) : EyerSIPMessgae()
    {
        osip_message_clone(sip, &impl->sip);
    }

    EyerSIPMessgae::~EyerSIPMessgae()
    {
        if(impl->sip != nullptr){
            osip_message_free(impl->sip);
            impl->sip = nullptr;
        }
        if(impl != nullptr){
            delete impl;
            impl = nullptr;
        }
    }

    int EyerSIPMessgae::GetFrom(EyerSIPFrom & from)
    {
        osip_from_t * osip_from = osip_message_get_from(impl->sip);
        osip_from_clone(osip_from, &from.impl->from);
        return 0;
    }

    EyerString EyerSIPMessgae::GetDeviceId()
    {
        return osip_message_get_from(impl->sip)->url->username;
    }

    EyerString EyerSIPMessgae::GetIp()
    {
        char addr[32];
        memset(addr, '\0', 32);

        osip_via_t* via = nullptr;
        osip_message_get_via(impl->sip, 0, &via);
        if(!via || !via->host) {
        }

        osip_generic_param_t * br = nullptr;
        osip_via_param_get_byname (via, (char *)"received", &br);
        if (br != NULL && br->gvalue != NULL)
            strcpy(addr, br->gvalue);
        else
            strcpy(addr, via->host);


        return addr;
    }

    EyerString EyerSIPMessgae::GetPort()
    {
        osip_via_t* via = nullptr;
        osip_message_get_via(impl->sip, 0, &via);
        if(!via || !via->host) {
            return "";
        }

        osip_generic_param_t * br = nullptr;
        osip_via_param_get_byname(via, (char *)"rport", &br);
        if(!br || !br->gvalue) {
            return "";
        }

        return br->gvalue;
    }

    EyerString EyerSIPMessgae::GetBody()
    {
        EyerString bodyStr;

        osip_body_t * dist = nullptr;
        osip_message_get_body(impl->sip, 0, &dist);
        if(dist != nullptr){
            bodyStr = dist->body;
        }

        return bodyStr;
    }
}
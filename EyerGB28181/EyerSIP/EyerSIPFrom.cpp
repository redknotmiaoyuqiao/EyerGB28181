#include "EyerSIPFrom.hpp"
#include "EyerSIPFromPrivate.hpp"

namespace Eyer
{
    EyerSIPFrom::EyerSIPFrom()
    {
        impl = new EyerSIPFromPrivate();
        osip_from_init(&impl->from);
    }

    EyerSIPFrom::~EyerSIPFrom()
    {
        if(impl->from != nullptr){
            osip_from_free(impl->from);
            impl->from = nullptr;
        }
        if(impl != nullptr){
            delete impl;
            impl = nullptr;
        }
    }

    EyerSIPFrom::EyerSIPFrom(const EyerSIPFrom & from)
    {
        *this = from;
    }

    EyerSIPFrom & EyerSIPFrom::operator = (const EyerSIPFrom & from)
    {
        osip_from_clone(from.impl->from, &impl->from);
        return *this;
    }

    int EyerSIPFrom::PrintfInfo()
    {
        printf("displayname: %s\n", impl->from->displayname);
        printf("scheme: %s\n", impl->from->url->scheme);
        printf("username: %s\n", impl->from->url->username);
        printf("password: %s\n", impl->from->url->password);
        printf("host: %s\n", impl->from->url->host);
        printf("port: %s\n", impl->from->url->port);
        return 0;
    }
}
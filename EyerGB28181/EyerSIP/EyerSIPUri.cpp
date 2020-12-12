#include "EyerSIPUri.hpp"
#include "EyerSIPUriPrivate.hpp"

namespace Eyer
{
    EyerSIPUri::EyerSIPUri()
    {
        impl = new EyerSIPUriPrivate();
        osip_uri_init(&impl->uri);
    }

    EyerSIPUri::~EyerSIPUri()
    {
        if(impl->uri != nullptr){
            osip_uri_free(impl->uri);
            impl->uri = nullptr;
        }
        if(impl != nullptr){
            delete impl;
            impl = nullptr;
        }
    }
}
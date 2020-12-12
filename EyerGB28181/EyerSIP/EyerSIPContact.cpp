#include "EyerSIPContact.hpp"
#include "EyerSIPContactPrivate.hpp"
#include "EyerSIPUriPrivate.hpp"

namespace Eyer
{
    EyerSIPContact::EyerSIPContact()
    {
        impl = new EyerSIPContactPrivate();
        osip_contact_init(&impl->contact);
    }

    EyerSIPContact::~EyerSIPContact()
    {
        if(impl->contact != nullptr){
            osip_contact_free(impl->contact);
            impl->contact = nullptr;
        }
        if(impl != nullptr){
            delete impl;
            impl = nullptr;
        }
    }

    int EyerSIPContact::GetUri(EyerSIPUri & uri)
    {
        osip_uri_clone(osip_contact_get_url(impl->contact), &uri.impl->uri);
        return 0;
    }
}
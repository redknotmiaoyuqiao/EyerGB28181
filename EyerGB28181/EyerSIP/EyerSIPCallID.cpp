#include "EyerSIPCallID.hpp"

#include "EyerSIPCallIDPrivate.hpp"

namespace Eyer
{
    EyerSIPCallID::EyerSIPCallID()
    {
        impl = new EyerSIPCallIDPrivate();
        osip_call_id_init(&impl->call_id);
    }

    EyerSIPCallID::~EyerSIPCallID()
    {
        if(impl->call_id != nullptr){
            osip_call_id_free(impl->call_id);
            impl->call_id = nullptr;
        }
        if(impl != nullptr){
            delete impl;
            impl = nullptr;
        }
    }
}
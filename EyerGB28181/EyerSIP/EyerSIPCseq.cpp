#include "EyerSIPCseq.hpp"
#include "EyerSIPCseqPrivate.hpp"

namespace Eyer
{
    EyerSIPCseq::EyerSIPCseq()
    {
        impl = new EyerSIPCseqPrivate();
        osip_cseq_init(&impl->cseq);
    }

    EyerSIPCseq::~EyerSIPCseq()
    {
        if(impl->cseq != nullptr){
            osip_cseq_free(impl->cseq);
            impl->cseq = nullptr;
        }
        if(impl != nullptr){
            delete impl;
            impl = nullptr;
        }
    }
}
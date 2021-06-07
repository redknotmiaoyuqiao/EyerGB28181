#ifndef EYERLIB_SIPPROCESSMESSAGE_HPP
#define EYERLIB_SIPPROCESSMESSAGE_HPP

#include "SIPProcess.hpp"

namespace Eyer
{
    class SIPProcessMessage : public SIPProcess {
    public:
        virtual int Process(GBServerContext * context, struct eXosip_t * excontext, eXosip_event_t * je);

    private:
        int UpdateIP_PORT(GBServerContext * context, EyerString & deviceId, osip_message_t * asw_register);
    };
}

#endif //EYERLIB_SIPPROCESSMESSAGE_HPP

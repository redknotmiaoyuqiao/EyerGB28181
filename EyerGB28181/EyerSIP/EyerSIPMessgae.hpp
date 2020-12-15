#ifndef EYERLIB_EYERSIPMESSGAE_HPP
#define EYERLIB_EYERSIPMESSGAE_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "EyerCore/EyerCore.hpp"
#include "EyerSIPFrom.hpp"
#include "EyerSIPCallID.hpp"
#include "EyerSIPCseq.hpp"
#include "EyerSIPContact.hpp"

#include <osipparser2/osip_parser.h>

namespace Eyer
{
    class EyerSIPMessgaePrivate;

    class EyerSIPMessgae {
    public:
        EyerSIPMessgae();
        EyerSIPMessgae(osip_message_t * sip);
        ~EyerSIPMessgae();

        int GetFrom(EyerSIPFrom & from);

        EyerString GetDeviceId();
        EyerString GetIp();
        EyerString GetPort();

        EyerString GetBody();
    private:
        EyerSIPMessgaePrivate * impl = nullptr;
    };
}

#endif //EYERLIB_EYERSIPMESSGAE_HPP

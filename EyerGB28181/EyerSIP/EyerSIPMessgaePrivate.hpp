#ifndef EYERLIB_EYERSIPMESSGAEPRIVATE_HPP
#define EYERLIB_EYERSIPMESSGAEPRIVATE_HPP

#include <osipparser2/osip_parser.h>
#include "EyerCore/EyerString.hpp"

namespace Eyer
{
    class EyerSIPMessgaePrivate
    {
    public:
        osip_message_t * sip = nullptr;
    };
}

#endif //EYERLIB_EYERSIPMESSGAEPRIVATE_HPP

#ifndef EYERLIB_EYERSIPURIPRIVATE_HPP
#define EYERLIB_EYERSIPURIPRIVATE_HPP

#include <osipparser2/osip_parser.h>

namespace Eyer
{
    class EyerSIPUriPrivate
    {
    public:
        osip_uri_t * uri = nullptr;
    };
}

#endif //EYERLIB_EYERSIPURIPRIVATE_HPP

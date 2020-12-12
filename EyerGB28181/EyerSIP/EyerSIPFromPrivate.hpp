#ifndef EYERLIB_EYERSIPFROMPRIVATE_HPP
#define EYERLIB_EYERSIPFROMPRIVATE_HPP

#include <osipparser2/osip_parser.h>

namespace Eyer
{
    class EyerSIPFromPrivate
    {
    public:
        osip_from_t * from = nullptr;
    };
}

#endif //EYERLIB_EYERSIPFROMPRIVATE_HPP

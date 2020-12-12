#ifndef EYERLIB_EYERSIPCONTACTPRIVATE_HPP
#define EYERLIB_EYERSIPCONTACTPRIVATE_HPP

#include <osipparser2/osip_parser.h>

namespace Eyer
{
    class EyerSIPContactPrivate
    {
    public:
        osip_contact_t * contact = nullptr;
    };
}

#endif //EYERLIB_EYERSIPCONTACTPRIVATE_HPP

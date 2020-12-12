#ifndef EYERLIB_EYERSIPCALLIDPRIVATE_HPP
#define EYERLIB_EYERSIPCALLIDPRIVATE_HPP

#include <osipparser2/osip_parser.h>

namespace Eyer
{
    class EyerSIPCallIDPrivate
    {
    public:
        osip_call_id_t * call_id = nullptr;
    };
}

#endif //EYERLIB_EYERSIPCALLIDPRIVATE_HPP

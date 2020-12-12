#ifndef EYERLIB_EYERSIPCSEQPRIVATE_HPP
#define EYERLIB_EYERSIPCSEQPRIVATE_HPP

#include <osipparser2/osip_parser.h>

namespace Eyer
{
    class EyerSIPCseqPrivate
    {
    public:
        osip_cseq_t * cseq = nullptr;
    };
}

#endif //EYERLIB_EYERSIPCSEQPRIVATE_HPP

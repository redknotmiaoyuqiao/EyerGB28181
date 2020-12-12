#ifndef EYERLIB_EYERSIPCSEQ_HPP
#define EYERLIB_EYERSIPCSEQ_HPP

namespace Eyer
{
    class EyerSIPCseqPrivate;
    class EyerSIPCseq {
    public:
        EyerSIPCseq();
        ~EyerSIPCseq();

    public:
        EyerSIPCseqPrivate * impl = nullptr;
    };
}

#endif //EYERLIB_EYERSIPCSEQ_HPP

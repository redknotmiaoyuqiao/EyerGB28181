#ifndef EYERLIB_EYERSIPCALLID_HPP
#define EYERLIB_EYERSIPCALLID_HPP

namespace Eyer
{
    class EyerSIPCallIDPrivate;
    class EyerSIPCallID {
    public:
        EyerSIPCallID();
        ~EyerSIPCallID();
    public:
        EyerSIPCallIDPrivate * impl = nullptr;
    };
}

#endif //EYERLIB_EYERSIPCALLID_HPP

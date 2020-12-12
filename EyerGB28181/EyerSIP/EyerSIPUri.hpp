#ifndef EYERLIB_EYERSIPURI_HPP
#define EYERLIB_EYERSIPURI_HPP

namespace Eyer
{
    class EyerSIPUriPrivate;
    class EyerSIPUri {
    public:
        EyerSIPUri();
        ~EyerSIPUri();
    public:
        EyerSIPUriPrivate * impl = nullptr;
    };
}

#endif //EYERLIB_EYERSIPURI_HPP

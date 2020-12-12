#ifndef EYERLIB_EYERSIPFROM_HPP
#define EYERLIB_EYERSIPFROM_HPP

namespace Eyer
{
    class EyerSIPFromPrivate;
    class EyerSIPFrom {
    public:
        EyerSIPFrom();
        ~EyerSIPFrom();
        EyerSIPFrom(const EyerSIPFrom & from);

        EyerSIPFrom & operator = (const EyerSIPFrom & from);

        int PrintfInfo();
    public:
        EyerSIPFromPrivate * impl = nullptr;
    };
}

#endif //EYERLIB_EYERSIPFROM_HPP

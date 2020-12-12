#ifndef EYERLIB_EYERSIPCONTACT_HPP
#define EYERLIB_EYERSIPCONTACT_HPP

#include "EyerSIPUri.hpp"

namespace Eyer {
    class EyerSIPContactPrivate;
    class EyerSIPContact {
    public:
        EyerSIPContact();
        ~EyerSIPContact();

        int GetUri(EyerSIPUri & uri);
    public:
        EyerSIPContactPrivate * impl = nullptr;
    };
}


#endif //EYERLIB_EYERSIPCONTACT_HPP

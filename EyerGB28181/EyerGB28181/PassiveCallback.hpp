#ifndef EYERLIB_PASSIVECALLBACK_HPP
#define EYERLIB_PASSIVECALLBACK_HPP

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class PassiveCallback {
    public:
        PassiveCallback();
        ~PassiveCallback();

        virtual int DeviceRegister  (EyerString deviceId) = 0;
        virtual int DeviceHeart     (EyerString deviceId) = 0;
    };
}

#endif //EYERLIB_PASSIVECALLBACK_HPP

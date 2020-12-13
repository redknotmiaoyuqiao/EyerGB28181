#ifndef EYERGB28181_JNIPASSIVECALLBACK_HPP
#define EYERGB28181_JNIPASSIVECALLBACK_HPP

#include "EyerGB28181/EyerGB28181.hpp"

namespace Eyer
{
    class JNIPassiveCallback : public PassiveCallback{
    public:
        virtual int UserRegister(EyerString deviceId);
    };
}

#endif //EYERGB28181_JNIPASSIVECALLBACK_HPP

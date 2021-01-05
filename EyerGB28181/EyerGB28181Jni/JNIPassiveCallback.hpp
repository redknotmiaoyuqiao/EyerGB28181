#ifndef EYERGB28181_JNIPASSIVECALLBACK_HPP
#define EYERGB28181_JNIPASSIVECALLBACK_HPP

#include "EyerGB28181/EyerGB28181.hpp"
#include "com_zzsin_eyer_gb28181_CInterface.h"

namespace Eyer
{
    class JNIPassiveCallback : public PassiveCallback{
    public:
        JNIPassiveCallback(jobject jPassiveCallback);
        ~JNIPassiveCallback();
    public:
        virtual int DeviceRegister(EyerString deviceId);
        virtual int DeviceHeart(EyerString deviceId);
    public:
        jobject jPassiveCallback;
    };
}

#endif //EYERGB28181_JNIPASSIVECALLBACK_HPP

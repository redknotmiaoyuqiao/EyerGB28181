#ifndef EYERGB28181_JNIPASSIVECALLBACK_HPP
#define EYERGB28181_JNIPASSIVECALLBACK_HPP

#include "EyerJNI/EyerJNI.hpp"
#include "EyerGB28181/EyerGB28181.hpp"

namespace Eyer
{
    class JNIPassiveCallback : public PassiveCallback {
    public:
        JNIPassiveCallback(jobject _jPassiveCallback);
        ~JNIPassiveCallback();

        virtual int DeviceRegister  (EyerString deviceId);
        virtual int DeviceHeart     (EyerString deviceId);

    public:
        jobject jPassiveCallback = nullptr;
    };
}

#endif //EYERGB28181_JNIPASSIVECALLBACK_HPP

#ifndef EYERGB28181_EYERJNIENVMANAGER_HPP
#define EYERGB28181_EYERJNIENVMANAGER_HPP

#include "JNIHeader.hpp"

namespace Eyer
{
    class EyerJNIEnvManager {
    public:
        static JavaVM * vm;

        static EyerJNIEnvManager * instance;
        static EyerJNIEnvManager * GetInstance();

        JNIEnv * AttachCurrentThread();
        int DetachCurrentThread();
    };
}

#endif //EYERGB28181_EYERJNIENVMANAGER_HPP

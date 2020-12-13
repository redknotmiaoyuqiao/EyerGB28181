#ifndef EYERGB28181_EYERJNIENVMANAGER_HPP
#define EYERGB28181_EYERJNIENVMANAGER_HPP

#include "jni.h"

namespace Eyer
{
    class EyerJNIEnvManager {
    public:
        static JavaVM * vm;

        static EyerJNIEnvManager * instance;
        static EyerJNIEnvManager * GetInstance();


    };
}

#endif //EYERGB28181_EYERJNIENVMANAGER_HPP

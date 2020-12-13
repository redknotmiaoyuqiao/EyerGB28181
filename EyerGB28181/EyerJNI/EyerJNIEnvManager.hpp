#ifndef EYERGB28181_EYERJNIENVMANAGER_HPP
#define EYERGB28181_EYERJNIENVMANAGER_HPP

#include "jni.h"

namespace Eyer
{
    class EyerJNIEnvManager {
    public:
        static JavaVM * vm;
    };
}

#endif //EYERGB28181_EYERJNIENVMANAGER_HPP

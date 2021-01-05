#ifndef EYERGB28181_EYERJNI_HPP
#define EYERGB28181_EYERJNI_HPP

#include "EyerJNIEnvManager.hpp"
#include "EyerJNIClazzLoader.hpp"

namespace Eyer
{
    class EyerJNI {

    };
}


#ifdef __cplusplus
extern "C" {
#endif

char * jstringtochar(JNIEnv *env, jstring jstr);

#ifdef __cplusplus
}
#endif

#endif //EYERGB28181_EYERJNI_HPP

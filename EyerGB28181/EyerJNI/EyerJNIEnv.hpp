#ifndef	EYER_LIB_JNI_UTIL_ENV_AV_H
#define	EYER_LIB_JNI_UTIL_ENV_AV_H

#include <jni.h>

namespace Eyer
{
    enum EyerJNIEnvMode
    {
        JAVA_THREAD,
        NATIVE_THREAD,
        UNKNOW,
    };

    class EyerJNIEnv
    {
    public:
        EyerJNIEnv();
        EyerJNIEnv(JNIEnv * env);
        ~EyerJNIEnv();

        EyerJNIEnv(const EyerJNIEnv & jniEnv);
        const EyerJNIEnv & operator = (const EyerJNIEnv & jniEnv);

    public:
        JNIEnv * env = nullptr;
        EyerJNIEnvMode mode = EyerJNIEnvMode::JAVA_THREAD;
    };
}

#endif //EYER_LIB_JNI_UTIL_ENV_AV_H
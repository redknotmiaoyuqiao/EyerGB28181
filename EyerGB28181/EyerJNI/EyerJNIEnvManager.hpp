#ifndef EYERCAMERAANDROID_EYERJNIENVMANAGER_HPP
#define EYERCAMERAANDROID_EYERJNIENVMANAGER_HPP

#include <jni.h>

namespace Eyer
{
    class EyerJNIEnvManager
    {
    public:
        static JavaVM * vm;

        static jobject clazzLoaderObject;
        static jmethodID findClassMethod;

        static EyerJNIEnvManager * instance;
        static EyerJNIEnvManager * GetInstance();

        JNIEnv * AttachCurrentThread();
        int DetachCurrentThread();

        jclass FindClazz(const char * name);
    };
}

#endif //EYERCAMERAANDROID_EYERJNIENVMANAGER_HPP

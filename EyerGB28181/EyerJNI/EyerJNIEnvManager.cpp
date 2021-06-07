#include "EyerJNIEnvManager.hpp"

namespace Eyer
{
    JavaVM * EyerJNIEnvManager::vm = nullptr;

    jobject EyerJNIEnvManager::clazzLoaderObject = nullptr;
    jmethodID EyerJNIEnvManager::findClassMethod = nullptr;

    EyerJNIEnvManager * EyerJNIEnvManager::instance = nullptr;

    EyerJNIEnvManager * EyerJNIEnvManager::GetInstance()
    {
        if(instance != nullptr){
            instance = new EyerJNIEnvManager();
        }
        return instance;
    }

    JNIEnv * EyerJNIEnvManager::AttachCurrentThread()
    {
        JNIEnv * env = nullptr;
        int status = EyerJNIEnvManager::vm->GetEnv((void **) &env, JNI_VERSION_1_6);
        if (status < 0) {
            EyerJNIEnvManager::vm->AttachCurrentThread((JNIEnv **)&env, NULL);
        }
        if(env == nullptr) {
            return nullptr;
        }
        return env;
    }

    int EyerJNIEnvManager::DetachCurrentThread()
    {
        EyerJNIEnvManager::vm->DetachCurrentThread();
        return 0;
    }

    jclass EyerJNIEnvManager::FindClazz(const char * name)
    {
        JNIEnv * env = AttachCurrentThread();
        return static_cast<jclass>(env->CallObjectMethod(clazzLoaderObject, findClassMethod, env->NewStringUTF(name)));
    }
}
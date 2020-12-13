#include "EyerJNIEnvManager.hpp"

namespace Eyer
{
    JavaVM * EyerJNIEnvManager::vm = nullptr;

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
        int status = Eyer::EyerJNIEnvManager::vm->GetEnv((void **) &env, JNI_VERSION_1_6);
        if (status < 0) {
            Eyer::EyerJNIEnvManager::vm->AttachCurrentThread((void **)&env, NULL);
        }
        if(env == nullptr) {
            return nullptr;
        }
        return env;
    }

    int EyerJNIEnvManager::DetachCurrentThread()
    {
        Eyer::EyerJNIEnvManager::vm->DetachCurrentThread();
        return 0;
    }
}
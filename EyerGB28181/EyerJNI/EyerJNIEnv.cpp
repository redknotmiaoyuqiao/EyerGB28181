#include "EyerJNIEnv.hpp"

#include "EyerJNIEnvManager.hpp"

namespace Eyer
{
    EyerJNIEnv::EyerJNIEnv()
    {
        env = nullptr;
        mode = EyerJNIEnvMode::UNKNOW;
    }

    EyerJNIEnv::EyerJNIEnv(JNIEnv * _env)
    {
        if(_env != nullptr) {
            // Java Thread
            env = _env;
            mode = EyerJNIEnvMode::JAVA_THREAD;
        }
        else {
            // Native Thread
            env = EyerJNIEnvManager::GetInstance()->AttachCurrentThread();
            mode = EyerJNIEnvMode::NATIVE_THREAD;
        }
    }

    EyerJNIEnv::~EyerJNIEnv()
    {
        if(mode == EyerJNIEnvMode::NATIVE_THREAD){
            EyerJNIEnvManager::GetInstance()->DetachCurrentThread();
        }
    }

    EyerJNIEnv::EyerJNIEnv(const EyerJNIEnv & jniEnv)
    {
        mode = EyerJNIEnvMode::UNKNOW;
        *this = jniEnv;
    }

    const EyerJNIEnv & EyerJNIEnv::operator = (const EyerJNIEnv & jniEnv)
    {
        env     = jniEnv.env;
        mode    = EyerJNIEnvMode::UNKNOW;
        return *this;
    }
}
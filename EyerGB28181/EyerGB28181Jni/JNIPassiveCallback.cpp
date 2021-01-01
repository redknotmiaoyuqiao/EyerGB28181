#include <EyerJNI/EyerJNIEnvManager.hpp>
#include "JNIPassiveCallback.hpp"

#include "EyerJNI/JNIHeader.hpp"

namespace Eyer
{
    JNIPassiveCallback::JNIPassiveCallback(jobject _jPassiveCallback)
    {
        jPassiveCallback = _jPassiveCallback;
    }

    int JNIPassiveCallback::UserRegister(EyerString _deviceId)
    {
        EyerLog("UserRegister UserRegister: %s\n", _deviceId.str);

        JNIEnv * env = EyerJNIEnvManager::GetInstance()->AttachCurrentThread();
        if(env == nullptr){
            return -1;
        }

        jclass classLoaderClass = env->FindClass("com/zzsin/eyer/gb28181/CInterface");
        if(classLoaderClass == nullptr){
            EyerLog("FFFFF Find classLoaderClass Class Fail\n");
            return -1;
        }

        jmethodID callbackMethodId = env->GetStaticMethodID(classLoaderClass, "eyer_gb_gbserver_passive_callback_UserRegister", "(Lcom/zzsin/eyer/gb28181/SIPPassiveCallback;Ljava/lang/String;)I");
        if(callbackMethodId == nullptr){
            EyerLog("FFFFF GetMethodID Fail\n");
            return -1;
        }

        jstring deviceId = env->NewStringUTF(_deviceId.str);
        jint ret = env->CallStaticIntMethod(classLoaderClass, callbackMethodId, jPassiveCallback, deviceId);

        EyerJNIEnvManager::GetInstance()->DetachCurrentThread();

        return ret;
    }

    int JNIPassiveCallback::DeviceHeart(Eyer::EyerString _deviceId)
    {
        JNIEnv * env = EyerJNIEnvManager::GetInstance()->AttachCurrentThread();
        if(env == nullptr){
            return -1;
        }

        jclass classLoaderClass = env->FindClass("com/zzsin/eyer/gb28181/CInterface");
        if(classLoaderClass == nullptr){
            EyerLog("FFFFF Find classLoaderClass Class Fail\n");
            return -1;
        }

        jmethodID callbackMethodId = env->GetStaticMethodID(classLoaderClass, "eyer_gb_gbserver_passive_callback_DeviceHeart", "(Lcom/zzsin/eyer/gb28181/SIPPassiveCallback;Ljava/lang/String;)I");
        if(callbackMethodId == nullptr){
            EyerLog("FFFFF GetMethodID Fail\n");
            return -1;
        }

        jstring deviceId = env->NewStringUTF(_deviceId.str);
        jint ret = env->CallStaticIntMethod(classLoaderClass, callbackMethodId, jPassiveCallback, deviceId);

        EyerJNIEnvManager::GetInstance()->DetachCurrentThread();
        return 0;
    }
}
#include "JNIPassiveCallback.hpp"

namespace Eyer
{
    JNIPassiveCallback::JNIPassiveCallback(jobject _jPassiveCallback)
    {
        jPassiveCallback = _jPassiveCallback;
    }

    JNIPassiveCallback::~JNIPassiveCallback()
    {

    }

    int JNIPassiveCallback::DeviceRegister  (EyerString deviceId)
    {
        EyerLog("JNIPassiveCallback DeviceRegister: %s\n", deviceId.str);

        JNIEnv * env = EyerJNIEnvManager::GetInstance()->AttachCurrentThread();
        if(env == nullptr){
            return -1;
        }

        jclass classLoaderClass = env->GetObjectClass(jPassiveCallback);
        if(classLoaderClass == nullptr){
            EyerLog("GetObjectClass Fail\n");
            return - 1;
        }

        jmethodID jmethodId = env->GetMethodID(classLoaderClass, "deviceRegister", "(Ljava/lang/String;)I");
        if(jmethodId == nullptr){
            EyerLog("GetMethodID Fail\n");
            return -1;
        }

        int ret = env->CallIntMethod(jPassiveCallback, jmethodId, env->NewStringUTF(deviceId.str));

        EyerJNIEnvManager::GetInstance()->DetachCurrentThread();

        return ret;
    }

    int JNIPassiveCallback::DeviceHeart     (EyerString deviceId)
    {
        EyerLog("JNIPassiveCallback DeviceHeart: %s\n", deviceId.str);

        JNIEnv * env = EyerJNIEnvManager::GetInstance()->AttachCurrentThread();
        if(env == nullptr){
            return -1;
        }

        jclass classLoaderClass = env->GetObjectClass(jPassiveCallback);
        if(classLoaderClass == nullptr){
            EyerLog("GetObjectClass Fail\n");
            return - 1;
        }

        jmethodID jmethodId = env->GetMethodID(classLoaderClass, "deviceHeart", "(Ljava/lang/String;)I");
        if(jmethodId == nullptr){
            EyerLog("GetMethodID Fail\n");
            return -1;
        }

        int ret = env->CallIntMethod(jPassiveCallback, jmethodId, env->NewStringUTF(deviceId.str));

        EyerJNIEnvManager::GetInstance()->DetachCurrentThread();

        return ret;
    }
}
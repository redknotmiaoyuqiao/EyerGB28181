#include <EyerJNI/EyerJNIEnvManager.hpp>
#include "JNIPassiveCallback.hpp"

#include "jni.h"

namespace Eyer
{
    JNIPassiveCallback::JNIPassiveCallback(jobject _jPassiveCallback)
    {
        jPassiveCallback = _jPassiveCallback;
    }

    int JNIPassiveCallback::UserRegister(EyerString _deviceId)
    {
        EyerLog("UserRegister UserRegister: %s\n", _deviceId.str);


        JNIEnv * env = nullptr;
        int status = Eyer::EyerJNIEnvManager::vm->GetEnv((void **) &env, JNI_VERSION_1_6);
        if (status < 0) {
            Eyer::EyerJNIEnvManager::vm->AttachCurrentThread((void **)&env, NULL);
        }
        if(env == nullptr) {
            EyerLog("AttachCurrentThread Fail\n");
            return -1;
        }

        jclass classLoaderClass = env->FindClass("com/zzsin/eyer/gb28181/CInterface");
        if(classLoaderClass == nullptr){
            EyerLog("FFFFF Find classLoaderClass Class Fail\n");
            return -1;
        }

        jmethodID callbackMethodId = env->GetStaticMethodID(classLoaderClass, "eyer_gb_sipserver_passive_callback_UserRegister", "(Lcom/zzsin/eyer/gb28181/SIPPassiveCallback;Ljava/lang/String;)I");
        if(callbackMethodId == nullptr){
            EyerLog("FFFFF GetMethodID Fail\n");
            return -1;
        }



        jstring deviceId = env->NewStringUTF(_deviceId.str);
        jint ret = env->CallStaticIntMethod(classLoaderClass, callbackMethodId, jPassiveCallback, deviceId);

        Eyer::EyerJNIEnvManager::vm->DetachCurrentThread();

        return ret;
    }
}
#include "com_zzsin_eyer_gb28181_CInterface.h"

#include "EyerJNI/EyerJNI.hpp"
#include "EyerCore/EyerCore.hpp"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM * vm, void * reserved)
{
    eyer_log_path("./eyer_gb_28181_log.txt");

    EyerLog("JavaVM GetEnv Success\n");

    Eyer::EyerJNIEnvManager::vm = vm;

    JNIEnv * env;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        EyerLog("JavaVM GetEnv Fail\n");
        return -1;
    }

    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM * vm, void * reserved)
{
    EyerLog("JNI_OnUnload");
}
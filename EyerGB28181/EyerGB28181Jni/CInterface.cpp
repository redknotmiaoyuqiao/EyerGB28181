#include "com_zzsin_eyer_gb28181_CInterface.h"
#include "EyerGB28181/EyerGB28181.hpp"
#include "JNIPassiveCallback.hpp"
#include "EyerJNI/EyerJNI.hpp"
#include "EyerGB28181/GBDeviceList.hpp"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM * vm, void * reserved)
{
    EyerLog("JavaVM GetEnv Success\n");

    Eyer::EyerJNIEnvManager::vm = vm;

    JNIEnv *env;
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

JNIEXPORT jstring JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1get_1version
(JNIEnv * env, jclass)
{
    return env->NewStringUTF("Eyer GB28181 0.2.0");
}

JNIEXPORT jlong JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1init
(JNIEnv *, jclass, jint port)
{
    Eyer::GBServer * sipserver = new Eyer::GBServer(port);
    return (jlong)sipserver;
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1uninit
(JNIEnv *, jclass, jlong sipserverJni)
{
    Eyer::GBServer * sipserver = (Eyer::GBServer *)sipserverJni;
    delete sipserver;

    return 0;
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1start
(JNIEnv *, jclass, jlong sipserverJni)
{
    Eyer::GBServer * sipserver = (Eyer::GBServer *)sipserverJni;
    return sipserver->Start();
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1stop
(JNIEnv *, jclass, jlong sipserverJni)
{
    Eyer::GBServer * sipserver = (Eyer::GBServer *)sipserverJni;
    return sipserver->Stop();
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1query_1devices
(JNIEnv *, jclass, jlong sipserverJNI, jlong deviceListJNI)
{
    Eyer::GBServer * sipserver = (Eyer::GBServer *)sipserverJNI;
    Eyer::GBDeviceList * deviceList = (Eyer::GBDeviceList *)deviceListJNI;

    return sipserver->GetDeviceList(*deviceList);
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1set_1passive_1callback
(JNIEnv *, jclass, jlong sipserverJni, jlong passiveCallbackJNI)
{
    Eyer::GBServer * sipserver = (Eyer::GBServer *)sipserverJni;
    Eyer::JNIPassiveCallback * passiveCallback = (Eyer::JNIPassiveCallback *)passiveCallbackJNI;
    return sipserver->SetCallback(passiveCallback);
}

JNIEXPORT jlong JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1passive_1callback_1init
(JNIEnv * env, jclass, jobject jPassiveCallback)
{
    jobject jo = env->NewGlobalRef(jPassiveCallback);
    Eyer::JNIPassiveCallback * passiveCallback = new Eyer::JNIPassiveCallback(jo);
    return (jlong)passiveCallback;
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1passive_1callback_1uninit
(JNIEnv *, jclass, jlong passiveCallbackJNI)
{
    Eyer::JNIPassiveCallback * passiveCallback = (Eyer::JNIPassiveCallback *)passiveCallbackJNI;
    delete passiveCallback;
    return 0;
}
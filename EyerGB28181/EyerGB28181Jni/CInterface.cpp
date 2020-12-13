#include "com_zzsin_eyer_gb28181_CInterface.h"
#include "EyerGB28181/EyerGB28181.hpp"
#include "JNIPassiveCallback.hpp"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    EyerLog("JavaVM GetEnv Success\n");



    return JNI_VERSION_1_6;
}

JNIEXPORT jstring JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1get_1version
(JNIEnv * env, jclass)
{
    return env->NewStringUTF("Eyer GB28181 1.0.0");
}

JNIEXPORT jlong JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1sipserver_1init
(JNIEnv *, jclass, jint port)
{
    Eyer::SIPServer * sipserver = new Eyer::SIPServer(port);
    return (jlong)sipserver;
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1sipserver_1uninit
(JNIEnv *, jclass, jlong sipserverJni)
{
    Eyer::SIPServer * sipserver = (Eyer::SIPServer *)sipserverJni;
    delete sipserver;

    return 0;
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1sipserver_1start
(JNIEnv *, jclass, jlong sipserverJni)
{
    Eyer::SIPServer * sipserver = (Eyer::SIPServer *)sipserverJni;
    return sipserver->Start();
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1sipserver_1stop
(JNIEnv *, jclass, jlong sipserverJni)
{
    Eyer::SIPServer * sipserver = (Eyer::SIPServer *)sipserverJni;
    return sipserver->Stop();
}


JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1sipserver_1set_1passive_1callback
(JNIEnv *, jclass, jlong sipserverJni, jlong passiveCallbackJNI)
{
    Eyer::SIPServer * sipserver = (Eyer::SIPServer *)sipserverJni;
    Eyer::JNIPassiveCallback * passiveCallback = (Eyer::JNIPassiveCallback *)passiveCallbackJNI;
    return sipserver->SetCallback(passiveCallback);
}

JNIEXPORT jlong JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1sipserver_1passive_1callback_1init
(JNIEnv * env, jclass, jobject jPassiveCallback)
{
    Eyer::JNIPassiveCallback * passiveCallback = new Eyer::JNIPassiveCallback();
    return (jlong)passiveCallback;
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1sipserver_1passive_1callback_1uninit
(JNIEnv *, jclass, jlong passiveCallbackJNI)
{
    Eyer::JNIPassiveCallback * passiveCallback = (Eyer::JNIPassiveCallback *)passiveCallbackJNI;
    delete passiveCallback;
    return 0;
}
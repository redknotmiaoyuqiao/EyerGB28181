#include "com_zzsin_eyer_gb28181_CInterface.h"
#include "EyerGB28181/EyerGB28181.hpp"
#include "JNIPassiveCallback.hpp"

Eyer::JNIPassiveCallback * jniPassiveCallback = nullptr;

JNIEXPORT jlong JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1init
(JNIEnv *, jclass, jint port)
{
    Eyer::GBServer * gbServer = new Eyer::GBServer(port);
    return (jlong)gbServer;
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1uninit
(JNIEnv * env, jclass, jlong gbServerJNI)
{
    Eyer::GBServer * gbServer = (Eyer::GBServer *)gbServerJNI;
    delete gbServer;

    if(jniPassiveCallback != nullptr){
        env->DeleteGlobalRef(jniPassiveCallback->jPassiveCallback);
        delete jniPassiveCallback;
        jniPassiveCallback = nullptr;
    }

    return 0;
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1start
(JNIEnv *, jclass, jlong gbServerJNI)
{
    Eyer::GBServer * gbServer = (Eyer::GBServer *)gbServerJNI;
    return gbServer->Start();
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1stop
(JNIEnv *, jclass, jlong gbServerJNI)
{
    Eyer::GBServer * gbServer = (Eyer::GBServer *)gbServerJNI;
    return gbServer->Stop();
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1set_1passive_1callback
(JNIEnv * env, jclass, jlong gbServerJNI, jobject jPassiveCallback)
{
    if(jniPassiveCallback != nullptr){
        delete jniPassiveCallback;
        jniPassiveCallback = nullptr;
    }

    jobject jo = env->NewGlobalRef(jPassiveCallback);
    jniPassiveCallback = new Eyer::JNIPassiveCallback(jo);

    Eyer::GBServer * gbServer = (Eyer::GBServer *)gbServerJNI;
    gbServer->SetCallback(jniPassiveCallback);
    return 0;
}
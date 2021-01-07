#include "com_zzsin_eyer_gb28181_CInterface.h"
#include "EyerGB28181/EyerGB28181.hpp"
#include "EyerJNI/EyerJNI.hpp"
#include "EyerGB28181/GBDeviceList.hpp"
#include "JNICatalogCallback.hpp"

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1catalog
(JNIEnv * env, jclass, jlong sipserverJni, jstring deviceIdJni, jlong callbackJni)
{
    Eyer::JNICatalogCallback * callback = (Eyer::JNICatalogCallback *)callbackJni;
    Eyer::GBServer * sipserver = (Eyer::GBServer *)sipserverJni;

    char * deviceId = jstringtochar(env, deviceIdJni);
    int ret = sipserver->Catalog(Eyer::EyerString(deviceId), callback);
    free(deviceId);

    return ret;
}

JNIEXPORT jlong JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1catalog_1callback_1init
(JNIEnv * env, jclass, jobject catalogCallback, jobject catalogDeviceList)
{
    jobject catalogCallbackGlobal = env->NewGlobalRef(catalogCallback);
    jobject catalogDeviceListGlobal = env->NewGlobalRef(catalogDeviceList);
    Eyer::JNICatalogCallback * callback = new Eyer::JNICatalogCallback(catalogCallbackGlobal, catalogDeviceListGlobal);
    return (jlong)callback;
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1catalog_1callback_1uninit
(JNIEnv *env, jclass, jlong callbackJni)
{
    Eyer::JNICatalogCallback * callback = (Eyer::JNICatalogCallback *)callbackJni;
    env->DeleteGlobalRef(callback->catalogCallbackJo);
    env->DeleteGlobalRef(callback->catalogDeviceListJo);
    delete callback;
    return 0;
}
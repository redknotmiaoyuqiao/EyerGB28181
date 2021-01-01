#include "com_zzsin_eyer_gb28181_CInterface.h"
#include "EyerGB28181/EyerGB28181.hpp"
#include "JNIPassiveCallback.hpp"
#include "EyerJNI/EyerJNI.hpp"
#include "EyerGB28181/GBDeviceList.hpp"

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1catalog
(JNIEnv *, jclass, jlong sipserverJni, jstring deviceId, jobject catalogCallback)
{
    Eyer::GBServer * sipserver = (Eyer::GBServer *)sipserverJni;
    // sipserver->Catalog()
    return 0;
}
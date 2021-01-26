#include "com_zzsin_eyer_gb28181_CInterface.h"

#include "EyerJNI/EyerJNI.hpp"
#include "EyerGB28181/EyerGB28181.hpp"
#include "JNICatalogCallback.hpp"

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1catalog
(JNIEnv * env, jclass, jlong gbServerJNI, jstring deviceIdJni, jobject)
{
    Eyer::GBServer * gbServer = (Eyer::GBServer *)gbServerJNI;

    // TODO Free
    Eyer::JNICatalogCallback * catalogCallback = new Eyer::JNICatalogCallback();

    char * deviceId = jstringtochar(env, deviceIdJni);
    int ret = gbServer->Catalog(deviceId, catalogCallback);
    free(deviceId);

    return ret;
}

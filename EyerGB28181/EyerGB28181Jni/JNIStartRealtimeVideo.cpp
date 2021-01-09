#include "com_zzsin_eyer_gb28181_CInterface.h"
#include "EyerGB28181/EyerGB28181.hpp"
#include "EyerJNI/EyerJNI.hpp"
#include "EyerGB28181/GBDeviceList.hpp"

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1start_1realtime_1video
(JNIEnv * env, jclass, jlong sipserverJni, jstring deviceIdJni)
{
    Eyer::GBServer * sipserver = (Eyer::GBServer *)sipserverJni;

    char * deviceId = jstringtochar(env, deviceIdJni);
    int ret = sipserver->StartStream("39.105.183.99", 1935, deviceId, nullptr);
    free(deviceId);

    return ret;
}
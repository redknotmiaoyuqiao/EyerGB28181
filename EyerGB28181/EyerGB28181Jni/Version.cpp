#include "com_zzsin_eyer_gb28181_CInterface.h"

JNIEXPORT jstring JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1get_1version
(JNIEnv * env, jclass)
{
    return env->NewStringUTF("Eyer GB28181 1.0.0");
}
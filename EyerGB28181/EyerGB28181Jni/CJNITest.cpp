#include "com_zzsin_eyer_gb28181_CInterface.h"

#include "TestThread.hpp"

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1jni_1test_1set_1callback
(JNIEnv * env, jclass, jobject callbackObj)
{
    jobject globalCallbackObj = env->NewGlobalRef(callbackObj);

    Eyer::TestThread * testThread = new Eyer::TestThread();
    testThread->Start();
    return 0;
}
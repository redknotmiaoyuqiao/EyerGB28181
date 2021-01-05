#include "com_zzsin_eyer_gb28181_CInterface.h"

#include "TestThread.hpp"

JNIEXPORT jlong JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1jni_1test_1set_1callback_1start
(JNIEnv * env, jclass, jobject callbackObj)
{
    jobject globalCallbackObj = env->NewGlobalRef(callbackObj);

    Eyer::TestThread * testThread = new Eyer::TestThread(globalCallbackObj);
    testThread->Start();
    return (jlong)testThread;
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1jni_1test_1set_1callback_1stop
(JNIEnv *, jclass, jlong testThreadJni)
{
    Eyer::TestThread * testThread = (Eyer::TestThread *)testThreadJni;
    testThread->Stop();
    delete testThread;
    return 0;
}
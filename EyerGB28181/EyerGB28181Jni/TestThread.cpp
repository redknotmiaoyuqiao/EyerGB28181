#include "TestThread.hpp"

namespace Eyer
{
    TestThread::TestThread(jobject _jo)
    {
        jo = _jo;
    }
    TestThread::~TestThread()
    {

    }
    void TestThread::Run()
    {
        JNIEnv * env = EyerJNIEnvManager::GetInstance()->AttachCurrentThread();
        if(env == nullptr){
            return;
        }

        jclass classLoaderClass = env->GetObjectClass(jo);
        if(classLoaderClass == nullptr){
            EyerLog("GetObjectClass Fail\n");
            return;
        }

        jmethodID jmethodId = env->GetMethodID(classLoaderClass, "callback", "(I)I");
        if(jmethodId == nullptr){
            EyerLog("GetMethodID Fail\n");
            return;
        }

        int ret = env->CallIntMethod(jo, jmethodId, 123);

        EyerJNIEnvManager::GetInstance()->DetachCurrentThread();
    }
}
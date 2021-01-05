#include "EyerJNI/EyerJNIEnvManager.hpp"
#include "JNICatalogCallback.hpp"

namespace Eyer
{
    JNICatalogCallback::JNICatalogCallback(jobject _catalogCallbackJo)
    {
        catalogCallbackJo = _catalogCallbackJo;
    }
    JNICatalogCallback::~JNICatalogCallback()
    {

    }

    int JNICatalogCallback::OnCatalog(int status, CataDeviceList & cataDeviceList)
    {
        JNIEnv * env = EyerJNIEnvManager::GetInstance()->AttachCurrentThread();
        if(env == nullptr){
            return -1;
        }

        jclass classLoaderClass = env->GetObjectClass(catalogCallbackJo);
        if(classLoaderClass == nullptr){
            EyerLog("GetObjectClass Fail\n");
            return - 1;
        }

        jmethodID jmethodId = env->GetMethodID(classLoaderClass, "OnCatalog", "(I)I");
        if(jmethodId == nullptr){
            EyerLog("GetMethodID Fail\n");
            return -1;
        }

        int ret = env->CallIntMethod(catalogCallbackJo, jmethodId, 0);

        EyerJNIEnvManager::GetInstance()->DetachCurrentThread();

        return ret;
    }
}
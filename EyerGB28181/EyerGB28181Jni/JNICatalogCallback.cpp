#include "EyerJNI/EyerJNIEnvManager.hpp"
#include "JNICatalogCallback.hpp"

namespace Eyer
{
    JNICatalogCallback::JNICatalogCallback(jobject _catalogCallbackJo, jobject _catalogDeviceListJo)
    {
        catalogCallbackJo = _catalogCallbackJo;
        catalogDeviceListJo = _catalogDeviceListJo;
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

        jmethodID jmethodId = env->GetMethodID(classLoaderClass, "OnCatalog", "(ILcom/zzsin/eyer/gb28181/callback/CatalogDeviceList;)I");
        if(jmethodId == nullptr){
            EyerLog("GetMethodID Fail\n");
            return -1;
        }



        jclass catalogDeviceListClassLoader = env->GetObjectClass(catalogDeviceListJo);
        if(catalogDeviceListClassLoader == nullptr){
            EyerLog("GetObjectClass Fail\n");
            return - 1;
        }
        jmethodID addCatalogDeviceJmethodId = env->GetMethodID(catalogDeviceListClassLoader, "addCatalogDevice", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I");
        if(addCatalogDeviceJmethodId == nullptr){
            EyerLog("GetMethodID Fail\n");
            return -1;
        }

        // CatalogDevice
        for(int i=0;i<cataDeviceList.Size();i++){
            CataDevice dataDevice;
            cataDeviceList.GetDevice(dataDevice, i);

            env->CallIntMethod(catalogDeviceListJo,
                               addCatalogDeviceJmethodId,
                               env->NewStringUTF(dataDevice.DeviceID.str),
                               env->NewStringUTF(dataDevice.Name.str),
                               env->NewStringUTF(dataDevice.Manufacturer.str),
                               env->NewStringUTF(dataDevice.Model.str),
                               env->NewStringUTF(dataDevice.Owner.str),
                               env->NewStringUTF(dataDevice.CivilCode.str),
                               env->NewStringUTF(dataDevice.Address.str),
                               env->NewStringUTF(dataDevice.Parental.str),
                               env->NewStringUTF(dataDevice.ParentID.str),
                               env->NewStringUTF(dataDevice.SafetyWay.str),
                               env->NewStringUTF(dataDevice.RegisterWay.str),
                               env->NewStringUTF(dataDevice.Secrecy.str),
                               env->NewStringUTF(dataDevice.Status.str)
                               );
        }


        int ret = env->CallIntMethod(catalogCallbackJo, jmethodId, 0, catalogDeviceListJo);

        EyerJNIEnvManager::GetInstance()->DetachCurrentThread();

        return ret;
    }
}
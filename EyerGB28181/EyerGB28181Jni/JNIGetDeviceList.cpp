#include "com_zzsin_eyer_gb28181_CInterface.h"
#include "EyerGB28181/EyerGB28181.hpp"

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1gbserver_1get_1device_1list
(JNIEnv * env, jclass, jlong gbServerJNI, jobject javaDeviceList)
{
    Eyer::GBServer * gbServer = (Eyer::GBServer *)gbServerJNI;

    Eyer::GBDeviceList gbDeviceList;
    gbServer->GetDeviceList(gbDeviceList);

    int size = gbDeviceList.Size();
    for(int i=0;i<size;i++){
        Eyer::GBDevice device;
        gbDeviceList.Get(device, i);
        Eyer::EyerString deviceId = device.GetDeviceID();

        jclass GBDeviceListclazz = env->FindClass("com/zzsin/eyer/gb28181/GBDeviceList");
        if(GBDeviceListclazz == nullptr){
            EyerLog("FindClass(com/zzsin/eyer/gb28181/GBDeviceList) Fail\n");
            continue;
        }

        jmethodID addDeviceMethod = env->GetMethodID(GBDeviceListclazz, "addDevice","(Ljava/lang/String;)I");
        if(addDeviceMethod == nullptr){
            EyerLog("GetMethodID(addDevice) Fail\n");
            continue;
        }

        int ret = env->CallIntMethod(javaDeviceList, addDeviceMethod, env->NewStringUTF(deviceId.str));
    }

    return 0;
}
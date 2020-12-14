#include "com_zzsin_eyer_gb28181_CInterface.h"
#include "EyerGB28181/GBDevice.hpp"
#include "EyerGB28181/GBDeviceList.hpp"

JNIEXPORT jlong JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1device_1list_1init
(JNIEnv *, jclass)
{
    Eyer::GBDeviceList * deviceList = new Eyer::GBDeviceList();
    return (jlong)deviceList;
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1device_1list_1uninit
(JNIEnv *, jclass, jlong deviceListJNI)
{
    Eyer::GBDeviceList * deviceList = (Eyer::GBDeviceList *)deviceListJNI;
    delete deviceList;
    return 0;
}

JNIEXPORT jint JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1device_1list_1size
(JNIEnv *, jclass, jlong deviceListJNI)
{
    Eyer::GBDeviceList * deviceList = (Eyer::GBDeviceList *)deviceListJNI;
    return deviceList->Size();
}

JNIEXPORT jstring JNICALL Java_com_zzsin_eyer_gb28181_CInterface_eyer_1gb_1device_1list_1get_1device_1id
(JNIEnv * env, jclass, jlong deviceListJNI, jint index)
{
    Eyer::GBDeviceList * deviceList = (Eyer::GBDeviceList *)deviceListJNI;

    Eyer::GBDevice device;
    deviceList->Get(device, index);

    return env->NewStringUTF(device.GetDeviceID().str);
}

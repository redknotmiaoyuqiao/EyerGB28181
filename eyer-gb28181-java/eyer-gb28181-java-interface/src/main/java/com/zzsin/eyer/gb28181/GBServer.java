package com.zzsin.eyer.gb28181;

import com.zzsin.eyer.gb28181.callback.CatalogCallback;
import com.zzsin.eyer.gb28181.callback.LoadCallback;
import com.zzsin.eyer.gb28181.callback.PassiveCallback;

public class GBServer extends JNIObject{
    public static int init(LoadCallback loadCallback){
        if(loadCallback != null){
            loadCallback.load("EyerGB28181Jni");
        }
        return 0;
    }

    public static String getVersion(){
        return CInterface.eyer_gb_get_version();
    }

    public GBServer(int port) {
        jniPtr = CInterface.eyer_gb_gbserver_init(port);
    }

    @Override
    public int destory() {
        if(jniPtr != 0){
            CInterface.eyer_gb_gbserver_uninit(jniPtr);
            jniPtr = 0;
        }
        return 0;
    }

    public int setPassiveCallback(PassiveCallback passiveCallback){
        return CInterface.eyer_gb_gbserver_set_passive_callback(jniPtr, passiveCallback);
    }

    public GBDeviceList getDeviceList(){
        GBDeviceList deviceList = new GBDeviceList();
        CInterface.eyer_gb_gbserver_get_device_list(jniPtr, deviceList);
        return deviceList;
    }

    public int catalog(String deviceId, CatalogCallback catalogCallback){
        return CInterface.eyer_gb_gbserver_catalog(jniPtr, deviceId, catalogCallback);
    }

    public int start() {
        return CInterface.eyer_gb_gbserver_start(jniPtr);
    }

    public int stop() {
        return CInterface.eyer_gb_gbserver_stop(jniPtr);
    }
}

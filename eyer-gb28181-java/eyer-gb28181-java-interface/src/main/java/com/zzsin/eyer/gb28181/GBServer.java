package com.zzsin.eyer.gb28181;

import com.zzsin.eyer.gb28181.callback.CatalogCallback;

import java.util.ArrayList;
import java.util.List;

public class GBServer extends JNIObject {

    public static int load(LoadCallback callback){
        callback.load("EyerGB28181Jni");
        return 0;
    }

    public static String getVersion(){
        return CInterface.eyer_gb_get_version();
    }

    public GBServer(int port){
        objId = CInterface.eyer_gb_gbserver_init(port);
    }

    public int destory() {
        if(objId != 0){
            CInterface.eyer_gb_gbserver_uninit(objId);
            objId = 0;
        }
        return 0;
    }

    public int start(){
        return CInterface.eyer_gb_gbserver_start(objId);
    }

    public int stop(){
        return CInterface.eyer_gb_gbserver_stop(objId);
    }

    public int setPassiveCallback(SIPPassiveCallback passiveCallback){
        return CInterface.eyer_gb_gbserver_set_passive_callback(objId, passiveCallback.objId);
    }

    public int catalog(String deviceId, CatalogCallback callback){
        return 0;
    }

    public List<Device> getDevices(){
        DeviceList deviceList = new DeviceList();
        CInterface.eyer_gb_gbserver_query_devices(objId, deviceList.objId);

        List<Device> devices = new ArrayList<Device>();

        for(int i=0;i<deviceList.size();i++){
            Device device = deviceList.getDevice(i);
            devices.add(device);
        }

        deviceList.destory();
        return devices;
    }
}

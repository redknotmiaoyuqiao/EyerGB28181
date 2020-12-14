package com.zzsin.eyer.gb28181;

import java.util.ArrayList;
import java.util.List;

public class SIPServer extends JNIObject {

    public static String getVersion(){
        return CInterface.eyer_gb_get_version();
    }

    public SIPServer(int port){
        objId = CInterface.eyer_gb_sipserver_init(port);
    }

    public int destory() {
        if(objId != 0){
            CInterface.eyer_gb_sipserver_uninit(objId);
            objId = 0;
        }
        return 0;
    }

    public int start(){
        return CInterface.eyer_gb_sipserver_start(objId);
    }

    public int stop(){
        return CInterface.eyer_gb_sipserver_stop(objId);
    }

    public int setPassiveCallback(SIPPassiveCallback passiveCallback){
        return CInterface.eyer_gb_sipserver_set_passive_callback(objId, passiveCallback.objId);
    }

    public List<Device> getDevices(){
        DeviceList deviceList = new DeviceList();
        CInterface.eyer_gb_sipserver_query_devices(objId, deviceList.objId);

        List<Device> devices = new ArrayList<Device>();

        for(int i=0;i<deviceList.size();i++){
            Device device = deviceList.getDevice(i);
            devices.add(device);
        }

        deviceList.destory();
        return devices;
    }
}

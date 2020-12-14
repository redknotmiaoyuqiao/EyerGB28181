package com.zzsin.eyer.gb28181;

public class DeviceList extends JNIObject{

    public DeviceList(){
        objId = CInterface.eyer_gb_device_list_init();
    }

    @Override
    public int destory() {
        if(objId != 0){
            CInterface.eyer_gb_device_list_uninit(objId);
            objId = 0;
        }
        return 0;
    }

    public int size(){
        return CInterface.eyer_gb_device_list_size(objId);
    }

    public Device getDevice(int index){
        Device device = new Device();

        String deviceId = CInterface.eyer_gb_device_list_get_device_id(objId, index);
        device.setDeviceId(deviceId);

        return device;
    }
}

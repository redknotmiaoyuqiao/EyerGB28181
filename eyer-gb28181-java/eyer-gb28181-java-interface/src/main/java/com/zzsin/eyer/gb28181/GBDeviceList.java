package com.zzsin.eyer.gb28181;

import java.util.ArrayList;
import java.util.List;

public class GBDeviceList {

    private List<String> deviceList = null;

    public GBDeviceList(){
        deviceList = new ArrayList<String>();
    }

    public int addDevice(String deviceId){
        deviceList.add(deviceId);
        return 0;
    }

    public int size(){
        return deviceList.size();
    }

    public String getDeviceId(int i){
        return deviceList.get(i);
    }
}

package com.zzsin.eyer.demo;

import com.zzsin.eyer.gb28181.SIPPassiveCallback;

public class DemoSIPPassiveCallback extends SIPPassiveCallback {
    public int UserRegister(String deviceId) {
        System.out.println("New Device Register: " + deviceId);
        return 0;
    }

    public int DeviceHeart(String deviceId) {
        System.out.println("Device Heart: " + deviceId);
        return 0;
    }
}

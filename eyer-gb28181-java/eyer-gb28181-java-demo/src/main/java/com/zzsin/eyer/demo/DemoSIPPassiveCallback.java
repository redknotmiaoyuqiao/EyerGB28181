package com.zzsin.eyer.demo;

import com.zzsin.eyer.gb28181.GBServer;
import com.zzsin.eyer.gb28181.SIPPassiveCallback;

public class DemoSIPPassiveCallback extends SIPPassiveCallback {

    private GBServer gbServer = null;
    private MyCatalogCallback catalogCallback = null;

    public DemoSIPPassiveCallback(GBServer gbServer) {
        this.gbServer = gbServer;
        this.catalogCallback = new MyCatalogCallback();
    }

    @Override
    public int destory() {
        this.catalogCallback.destory();
        return super.destory();
    }

    public int DeviceRegister(String deviceId) {
        System.out.println("New Device Register: " + deviceId);
        this.gbServer.startRealtimeVideo(deviceId);
        return 0;
    }

    public int DeviceHeart(String deviceId) {
        System.out.println("Device Heart: " + deviceId);

        this.gbServer.catalog(deviceId, this.catalogCallback);

        return 0;
    }
}

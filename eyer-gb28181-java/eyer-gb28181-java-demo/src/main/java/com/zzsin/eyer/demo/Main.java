package com.zzsin.eyer.demo;

import com.zzsin.eyer.gb28181.CInterface;
import com.zzsin.eyer.gb28181.Device;
import com.zzsin.eyer.gb28181.GBServer;
import com.zzsin.eyer.gb28181.LoadCallback;
import com.zzsin.eyer.gb28181.callback.TestCallback;

import java.util.List;

class MyLoadCallback extends LoadCallback
{
    public int load(String libName) {
        if("EyerGB28181Jni".equals(libName)){
            // System.load("/Users/yuqiaomiao/GitHub/EyerGB28181/EyerGB28181/cmake-build-debug/EyerGB28181Jni/libEyerGB28181Jni.dylib");
            System.load("/Users/lichi/EyerGB28181/EyerGB28181/cmake-build-debug/EyerGB28181Jni/libEyerGB28181Jni.dylib");
        }
        return 0;
    }
}

class MyTestCallback extends TestCallback
{
    @Override
    public int callback(int a) {
        System.out.println("a: " + a);
        return 0;
    }
}

public class Main {
    public static void main(String[] args){
        GBServer.load(new MyLoadCallback());

        long a = CInterface.eyer_jni_test_set_callback_start(new MyTestCallback());
        CInterface.eyer_jni_test_set_callback_stop(a);

        /*

        System.out.println(GBServer.getVersion());

        DemoSIPPassiveCallback demoSIPPassiveCallback = new DemoSIPPassiveCallback();

        GBServer gbServer = new GBServer(5060);
        gbServer.setPassiveCallback(demoSIPPassiveCallback);
        gbServer.start();

        for(int i=0;i<60 * 2;i++){
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            // System.out.println("=====getDevices=====");
            List<Device> devices = gbServer.getDevices();
            for(Device device : devices){
                //System.out.println("Device: " + device.getDeviceId());
            }
        }

        gbServer.stop();
        gbServer.destory();

        demoSIPPassiveCallback.destory();

         */
    }
}

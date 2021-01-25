package com.zzsin.eyer.demo;

import com.zzsin.eyer.gb28181.GBServer;
import com.zzsin.eyer.gb28181.callback.LoadCallback;
import com.zzsin.eyer.gb28181.callback.PassiveCallback;

class MyLoadCallback implements LoadCallback
{
    public int load(String libName) {
        if("EyerGB28181Jni".equals(libName)){
            System.load("/Users/yuqiaomiao/GitHub/EyerGB28181/EyerGB28181/cmake-build-debug/EyerGB28181Jni/libEyerGB28181Jni.dylib");
            // System.load("/Users/lichi/EyerGB28181/EyerGB28181/cmake-build-debug/EyerGB28181Jni/libEyerGB28181Jni.dylib");
            // System.load("/root/EyerGB28181/EyerGB28181/cmake-build-debug/EyerGB28181Jni/libEyerGB28181Jni.so");
        }
        return 0;
    }
}

class MyPassiveCallback implements PassiveCallback
{
    @Override
    public int deviceRegister(String deviceId) {
        System.out.println("Java deviceRegister: " + deviceId);
        return 0;
    }

    @Override
    public int deviceHeart(String deviceId) {
        System.out.println("Java deviceHeart: " + deviceId);
        return 0;
    }
}

public class Main {
    public static void main(String[] args){
        GBServer.init(new MyLoadCallback());

        String version = GBServer.getVersion();
        System.out.println("version: " + version);

        GBServer gbServer = new GBServer(5060);
        gbServer.setPassiveCallback(new MyPassiveCallback());
        gbServer.start();

        for(int i=0;i<60;i++){
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        gbServer.stop();
        gbServer.destory();
    }
}

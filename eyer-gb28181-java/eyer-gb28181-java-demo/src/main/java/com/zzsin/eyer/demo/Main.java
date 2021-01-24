package com.zzsin.eyer.demo;

import com.zzsin.eyer.gb28181.GBServer;
import com.zzsin.eyer.gb28181.callback.LoadCallback;

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

public class Main {
    public static void main(String[] args){
        GBServer.init(new MyLoadCallback());
    }
}

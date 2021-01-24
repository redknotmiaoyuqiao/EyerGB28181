package com.zzsin.eyer.gb28181;

import com.zzsin.eyer.gb28181.callback.LoadCallback;

public class GBServer {
    public static int init(LoadCallback loadCallback){
        if(loadCallback != null){
            loadCallback.load("EyerGB28181Jni");
        }
        return 0;
    }
}

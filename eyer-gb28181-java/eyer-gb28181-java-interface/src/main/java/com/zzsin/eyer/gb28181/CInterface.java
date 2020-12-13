package com.zzsin.eyer.gb28181;

public class CInterface {
    static {
        // System.setProperty("java.library.path", "/Users/yuqiaomiao/GitHub/EyerGB28181/EyerGB28181/cmake-build-debug/EyerGB28181Jni/");
        System.load("/Users/yuqiaomiao/GitHub/EyerGB28181/EyerGB28181/cmake-build-debug/EyerGB28181Jni/libEyerGB28181Jni.dylib");
        // System.loadLibrary("EyerGB28181Jni");
    }

    public static native String eyer_gb_get_version();

    public static native long   eyer_gb_sipserver_init      (int port);
    public static native int    eyer_gb_sipserver_uninit    (long sipserver);

    public static native int    eyer_gb_sipserver_start     (long sipserver);
    public static native int    eyer_gb_sipserver_stop      (long sipserver);

    public static native int    eyer_gb_sipserver_set_passive_callback          (long sipserver, long callback);



    public static native long   eyer_gb_sipserver_passive_callback_init         (SIPPassiveCallback passiveCallback);
    public static native int    eyer_gb_sipserver_passive_callback_uninit       (long callback);

    public static int eyer_gb_sipserver_passive_callback_UserRegister           (SIPPassiveCallback passiveCallback, String deviceId)
    {
        System.out.println("eyer_gb_sipserver_passive_callback_UserRegister: " + deviceId);
        System.out.println("eyer_gb_sipserver_passive_callback_UserRegister: " + passiveCallback.toString());
        return 0;
    }
}

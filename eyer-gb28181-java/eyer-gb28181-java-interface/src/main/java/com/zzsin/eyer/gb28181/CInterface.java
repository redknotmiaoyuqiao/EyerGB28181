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

    public static native int    eyer_gb_sipserver_query_devices                 (long sipserver, long list);


    public static native long   eyer_gb_device_list_init                ();
    public static native int    eyer_gb_device_list_uninit              (long list);
    public static native int    eyer_gb_device_list_size                (long list);
    public static native String eyer_gb_device_list_get_device_id       (long list, int index);



    public static native long   eyer_gb_sipserver_passive_callback_init         (SIPPassiveCallback passiveCallback);
    public static native int    eyer_gb_sipserver_passive_callback_uninit       (long callback);

    public static int eyer_gb_sipserver_passive_callback_UserRegister           (SIPPassiveCallback passiveCallback, String deviceId)
    {
        return passiveCallback.UserRegister(deviceId);
    }

    public static int eyer_gb_sipserver_passive_callback_DeviceHeart            (SIPPassiveCallback passiveCallback, String deviceId)
    {
        return passiveCallback.DeviceHeart(deviceId);
    }
}

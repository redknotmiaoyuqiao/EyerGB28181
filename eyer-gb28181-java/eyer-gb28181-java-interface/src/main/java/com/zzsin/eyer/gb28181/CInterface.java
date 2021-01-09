package com.zzsin.eyer.gb28181;

import com.zzsin.eyer.gb28181.callback.CatalogCallback;
import com.zzsin.eyer.gb28181.callback.CatalogDeviceList;
import com.zzsin.eyer.gb28181.callback.TestCallback;

public class CInterface {
    // static {
        // System.setProperty("java.library.path", "/Users/yuqiaomiao/GitHub/EyerGB28181/EyerGB28181/cmake-build-debug/EyerGB28181Jni/");
        // System.load("/Users/yuqiaomiao/GitHub/EyerGB28181/EyerGB28181/cmake-build-debug/EyerGB28181Jni/libEyerGB28181Jni.dylib");
        // System.loadLibrary("EyerGB28181Jni");
    // }

    public static native String eyer_gb_get_version();

    public static native long   eyer_gb_gbserver_init      (int port);
    public static native int    eyer_gb_gbserver_uninit    (long gbserver);

    public static native int    eyer_gb_gbserver_start     (long gbserver);
    public static native int    eyer_gb_gbserver_stop      (long gbserver);

    public static native int    eyer_gb_gbserver_set_passive_callback          (long gbserver, long callback);

    public static native int    eyer_gb_gbserver_query_devices                 (long gbserver, long list);


    public static native long   eyer_gb_device_list_init                ();
    public static native int    eyer_gb_device_list_uninit              (long list);
    public static native int    eyer_gb_device_list_size                (long list);
    public static native String eyer_gb_device_list_get_device_id       (long list, int index);

    public static native long   eyer_gb_gbserver_passive_callback_init         (SIPPassiveCallback passiveCallback);
    public static native int    eyer_gb_gbserver_passive_callback_uninit       (long callback);


    public static native int    eyer_gb_gbserver_catalog                (long gbserver, String deviceId, long catalog_callback);
    public static native long   eyer_gb_catalog_callback_init           (CatalogCallback callback, CatalogDeviceList deviceList);
    public static native int    eyer_gb_catalog_callback_uninit         (long catalog_callback);

    public static native int    eyer_gb_gbserver_start_realtime_video   (long gbserver, String deviceId);

    public static native int    eyer_gb_gbserver_stop_realtime_video    (long gbserver);

    public static native long   eyer_jni_test_set_callback_start                  (TestCallback testCallback);
    public static native int    eyer_jni_test_set_callback_stop                   (long test);

}

package com.zzsin.eyer.gb28181;

public class CInterface {
    static {
        
    }

    public static native String eyer_gb_get_version();

    public static native long   eyer_gb_sipserver_init      (int port);
    public static native int    eyer_gb_sipserver_uninit    (long sipserver);

    public static native int    eyer_gb_sipserver_start     (long sipserver);
    public static native int    eyer_gb_sipserver_stop      (long sipserver);
}

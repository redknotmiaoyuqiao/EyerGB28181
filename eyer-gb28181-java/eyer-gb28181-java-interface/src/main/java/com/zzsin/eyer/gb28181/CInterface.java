package com.zzsin.eyer.gb28181;

import com.zzsin.eyer.gb28181.callback.CatalogCallback;
import com.zzsin.eyer.gb28181.callback.PassiveCallback;

public class CInterface {
    public static native String eyer_gb_get_version();

    public static native long   eyer_gb_gbserver_init      (int port);
    public static native int    eyer_gb_gbserver_uninit    (long gbserver);

    public static native int    eyer_gb_gbserver_start     (long gbserver);
    public static native int    eyer_gb_gbserver_stop      (long gbserver);

    public static native int    eyer_gb_gbserver_set_passive_callback       (long gbserver, PassiveCallback callback);

    public static native int    eyer_gb_gbserver_get_device_list            (long gbserver, GBDeviceList deviceList);

    public static native int    eyer_gb_gbserver_catalog    (long gbserver, String deviceId, CatalogCallback catalogCallback);
}

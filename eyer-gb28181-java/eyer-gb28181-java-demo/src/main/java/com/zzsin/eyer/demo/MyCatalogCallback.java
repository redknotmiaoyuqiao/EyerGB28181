package com.zzsin.eyer.demo;

import com.zzsin.eyer.gb28181.callback.CataDevice;
import com.zzsin.eyer.gb28181.callback.CatalogCallback;

import java.util.List;

public class MyCatalogCallback extends CatalogCallback {
    @Override
    public int OnCatalog(int status) {
        System.out.println("OnCatalog: " + status);
        return 0;
    }
    /*
    @Override
    public int OnCatalog(int status, List<CataDevice> cataDeviceList) {
        return 0;
    }
    */
}

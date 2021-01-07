package com.zzsin.eyer.demo;

import com.zzsin.eyer.gb28181.callback.CatalogCallback;
import com.zzsin.eyer.gb28181.callback.CatalogDeviceList;

public class MyCatalogCallback extends CatalogCallback {
    @Override
    public int OnCatalog(int status, CatalogDeviceList catalogDeviceList) {
        System.out.println("OnCatalog: " + status);
        return 0;
    }
}

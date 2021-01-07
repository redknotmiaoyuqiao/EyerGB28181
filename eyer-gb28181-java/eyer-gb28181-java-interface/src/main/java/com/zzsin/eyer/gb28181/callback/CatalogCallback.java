package com.zzsin.eyer.gb28181.callback;

import com.zzsin.eyer.gb28181.CInterface;
import com.zzsin.eyer.gb28181.JNIObject;

import java.util.List;

public abstract class CatalogCallback extends JNIObject {
    public CatalogCallback(){
        objId = CInterface.eyer_gb_catalog_callback_init(this, new CatalogDeviceList());
    }

    public int destory() {
        if(objId != 0){
            CInterface.eyer_gb_catalog_callback_uninit(objId);
            objId = 0;
        }
        return 0;
    }
    // public abstract int OnCatalog(int status, List<CataDevice> cataDeviceList);
    public abstract int OnCatalog(int status, CatalogDeviceList deviceList);
}

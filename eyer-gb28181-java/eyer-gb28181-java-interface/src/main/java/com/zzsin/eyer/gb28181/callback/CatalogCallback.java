package com.zzsin.eyer.gb28181.callback;

import java.util.List;

public abstract class CatalogCallback {
    public abstract int OnCatalog(int status, List<CataDevice> cataDeviceList);
}

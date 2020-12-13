package com.zzsin.eyer.gb28181;

public abstract class SIPPassiveCallback extends JNIObject {
    public SIPPassiveCallback(){
        objId = CInterface.eyer_gb_sipserver_passive_callback_init();
    }

    public int destory() {
        if(objId != 0){
            CInterface.eyer_gb_sipserver_passive_callback_uninit(objId);
            objId = 0;
        }
        return 0;
    }

    public abstract int UserRegister(String deviceId);
}

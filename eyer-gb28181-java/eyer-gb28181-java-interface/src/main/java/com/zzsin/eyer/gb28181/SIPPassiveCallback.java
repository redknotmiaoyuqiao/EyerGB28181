package com.zzsin.eyer.gb28181;

public class SIPPassiveCallback extends JNIObject {
    public SIPPassiveCallback(int port){
        objId = CInterface.eyer_gb_sipserver_passive_callback_init(this);
    }

    public int destory() {
        if(objId != 0){
            CInterface.eyer_gb_sipserver_passive_callback_uninit(objId);
            objId = 0;
        }
        return 0;
    }
}

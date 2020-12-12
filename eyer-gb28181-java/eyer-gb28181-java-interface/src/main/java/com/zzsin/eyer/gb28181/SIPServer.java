package com.zzsin.eyer.gb28181;

public class SIPServer extends JNIObject {

    public static String getVersion(){
        return CInterface.eyer_gb_get_version();
    }

    public SIPServer(int port){
        objId = CInterface.eyer_gb_sipserver_init(port);
    }

    public int destory() {
        if(objId != 0){
            CInterface.eyer_gb_sipserver_uninit(objId);
            objId = 0;
        }
        return 0;
    }

    public int Start(){
        return CInterface.eyer_gb_sipserver_start(objId);
    }

    public int Stop(){
        return CInterface.eyer_gb_sipserver_stop(objId);
    }
}

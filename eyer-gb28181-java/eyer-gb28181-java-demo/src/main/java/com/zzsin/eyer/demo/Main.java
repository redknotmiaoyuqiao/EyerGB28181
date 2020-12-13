package com.zzsin.eyer.demo;

import com.zzsin.eyer.gb28181.SIPServer;

public class Main {
    public static void main(String[] args){
        System.out.println(SIPServer.getVersion());

        DemoSIPPassiveCallback demoSIPPassiveCallback = new DemoSIPPassiveCallback();

        SIPServer sipServer = new SIPServer(5060);
        sipServer.setPassiveCallback(demoSIPPassiveCallback);
        sipServer.start();

        for(int i=0;i<60 * 1;i++){
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            // System.out.println(i + "");
        }

        sipServer.stop();
        sipServer.destory();

        demoSIPPassiveCallback.destory();
    }
}

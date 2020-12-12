package com.zzsin.eyer.demo;

import com.zzsin.eyer.gb28181.SIPServer;

public class Main {
    public static void main(String[] args){
        System.out.println("Hello World\n");

        SIPServer sipServer = new SIPServer(5060);
        sipServer.Start();

        for(int i=0;i<60 * 2;i++){
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        sipServer.Stop();
        sipServer.destory();
    }
}

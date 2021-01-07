package com.zzsin.eyer.gb28181.callback;

import java.util.LinkedList;
import java.util.List;

public class CatalogDeviceList {

    private List<CatalogDevice> deviceList;

    public CatalogDeviceList(){
        deviceList = new LinkedList<CatalogDevice>();
    }

    public int addCatalogDevice(
            String DeviceID,
            String Name,
            String Manufacturer,
            String Model,
            String Owner,
            String CivilCode,
            String Address,
            String Parental,
            String ParentID,
            String SafetyWay,
            String RegisterWay,
            String Secrecy,
            String Status
    ){
        CatalogDevice device = new CatalogDevice(DeviceID, Name, Manufacturer, Model, Owner, CivilCode, Address, Parental, ParentID, SafetyWay, RegisterWay, Secrecy, Status);
        deviceList.add(device);
        return 0;
    }

    public int PrintInfo(){
        for(CatalogDevice device : deviceList){
            System.out.println("==================");
            device.PrintInfo();
        }
        return 0;
    }

    public List<CatalogDevice> getDeviceList() {
        return deviceList;
    }
}

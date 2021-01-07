package com.zzsin.eyer.gb28181.callback;

public class CatalogDevice {
    private String DeviceID;
    private String Name;
    private String Manufacturer;
    private String Model;
    private String Owner;
    private String CivilCode;
    private String Address;
    private String Parental;
    private String ParentID;
    private String SafetyWay;
    private String RegisterWay;
    private String Secrecy;
    private String Status;

    public CatalogDevice(){

    }

    public CatalogDevice(
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
        this.DeviceID = DeviceID;
        this.Name = Name;
        this.Manufacturer = Manufacturer;
        this.Model = Model;
        this.Owner = Owner;
        this.CivilCode = CivilCode;
        this.Address = Address;
        this.Parental = Parental;
        this.ParentID = ParentID;
        this.SafetyWay = SafetyWay;
        this.RegisterWay = RegisterWay;
        this.Secrecy = Secrecy;
        this.Status = Status;
    }

    public int PrintInfo()
    {
        System.out.println("DeviceID: " + DeviceID);
        System.out.println("Name: " + Name);
        System.out.println("Manufacturer: " + Manufacturer);
        System.out.println("Model: " + Model);
        System.out.println("Owner: " + Owner);
        System.out.println("CivilCode: " + CivilCode);
        System.out.println("Address: " + Address);
        System.out.println("Parental: " + Parental);
        System.out.println("ParentID: " + ParentID);
        System.out.println("SafetyWay: " + SafetyWay);
        System.out.println("RegisterWay: " + RegisterWay);
        System.out.println("Secrecy: " + Secrecy);
        System.out.println("Status: " + Status);
        return 0;
    }

    public String getDeviceID() {
        return DeviceID;
    }

    public void setDeviceID(String deviceID) {
        DeviceID = deviceID;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public String getManufacturer() {
        return Manufacturer;
    }

    public void setManufacturer(String manufacturer) {
        Manufacturer = manufacturer;
    }

    public String getModel() {
        return Model;
    }

    public void setModel(String model) {
        Model = model;
    }

    public String getOwner() {
        return Owner;
    }

    public void setOwner(String owner) {
        Owner = owner;
    }

    public String getCivilCode() {
        return CivilCode;
    }

    public void setCivilCode(String civilCode) {
        CivilCode = civilCode;
    }

    public String getAddress() {
        return Address;
    }

    public void setAddress(String address) {
        Address = address;
    }

    public String getParental() {
        return Parental;
    }

    public void setParental(String parental) {
        Parental = parental;
    }

    public String getParentID() {
        return ParentID;
    }

    public void setParentID(String parentID) {
        ParentID = parentID;
    }

    public String getSafetyWay() {
        return SafetyWay;
    }

    public void setSafetyWay(String safetyWay) {
        SafetyWay = safetyWay;
    }

    public String getRegisterWay() {
        return RegisterWay;
    }

    public void setRegisterWay(String registerWay) {
        RegisterWay = registerWay;
    }

    public String getSecrecy() {
        return Secrecy;
    }

    public void setSecrecy(String secrecy) {
        Secrecy = secrecy;
    }

    public String getStatus() {
        return Status;
    }

    public void setStatus(String status) {
        Status = status;
    }
}

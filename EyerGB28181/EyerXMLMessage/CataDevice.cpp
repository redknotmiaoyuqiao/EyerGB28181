#include "CataDevice.hpp"

/*
<DeviceID>34020000001320000001</DeviceID>
<Name>Camera 01</Name>
<Manufacturer>Hikvision</Manufacturer>
<Model>IP Camera</Model>
<Owner>Owner</Owner>
<CivilCode>3402000000</CivilCode>
<Address>Address</Address>
<Parental>0</Parental>
<ParentID>34020000002000000001</ParentID>
<SafetyWay>0</SafetyWay>
<RegisterWay>1</RegisterWay>
<Secrecy>0</Secrecy>
<Status>ON</Status>
 */

namespace Eyer
{
    CataDevice::CataDevice()
    {

    }

    CataDevice::CataDevice(const CataDevice & cataDevice)
    {
        *this = cataDevice;
    }

    CataDevice::~CataDevice()
    {

    }

    const CataDevice & CataDevice::operator = (const CataDevice & cataDevice)
    {
        DeviceID    = cataDevice.DeviceID;
        Name        = cataDevice.Name;
        Manufacturer= cataDevice.Manufacturer;
        Model       = cataDevice.Model;
        Owner       = cataDevice.Owner;
        CivilCode   = cataDevice.CivilCode;
        Address     = cataDevice.Address;
        Parental    = cataDevice.Parental;
        ParentID    = cataDevice.ParentID;
        SafetyWay   = cataDevice.SafetyWay;
        RegisterWay = cataDevice.RegisterWay;
        Secrecy     = cataDevice.Secrecy;
        Status      = cataDevice.Status;

        return *this;
    }

    int CataDevice::Parse(tinyxml2::XMLElement * itemElement)
    {
        tinyxml2::XMLElement * DeviceIDElement = itemElement->FirstChildElement("DeviceID");
        if(DeviceIDElement != nullptr){
            DeviceID = DeviceIDElement->GetText();
        }

        tinyxml2::XMLElement * NameElement = itemElement->FirstChildElement("Name");
        if(NameElement != nullptr){
            Name = NameElement->GetText();
        }

        tinyxml2::XMLElement * ManufacturerElement = itemElement->FirstChildElement("Manufacturer");
        if(ManufacturerElement != nullptr){
            Manufacturer = ManufacturerElement->GetText();
        }

        tinyxml2::XMLElement * ModelElement = itemElement->FirstChildElement("Model");
        if(ModelElement != nullptr){
            Model = ModelElement->GetText();
        }

        tinyxml2::XMLElement * OwnerElement = itemElement->FirstChildElement("Owner");
        if(OwnerElement != nullptr){
            Owner = OwnerElement->GetText();
        }

        tinyxml2::XMLElement * CivilCodeElement = itemElement->FirstChildElement("CivilCode");
        if(CivilCodeElement != nullptr){
            CivilCode = CivilCodeElement->GetText();
        }

        tinyxml2::XMLElement * AddressElement = itemElement->FirstChildElement("Address");
        if(AddressElement != nullptr){
            Address = AddressElement->GetText();
        }

        tinyxml2::XMLElement * ParentalElement = itemElement->FirstChildElement("Parental");
        if(ParentalElement != nullptr){
            Parental = ParentalElement->GetText();
        }

        tinyxml2::XMLElement * ParentIDElement = itemElement->FirstChildElement("ParentID");
        if(ParentIDElement != nullptr){
            ParentID = ParentIDElement->GetText();
        }

        tinyxml2::XMLElement * SafetyWayElement = itemElement->FirstChildElement("SafetyWay");
        if(SafetyWayElement != nullptr){
            SafetyWay = SafetyWayElement->GetText();
        }

        tinyxml2::XMLElement * RegisterWayElement = itemElement->FirstChildElement("RegisterWay");
        if(RegisterWayElement != nullptr){
            RegisterWay = RegisterWayElement->GetText();
        }

        tinyxml2::XMLElement * SecrecyElement = itemElement->FirstChildElement("Secrecy");
        if(SecrecyElement != nullptr){
            Secrecy = SecrecyElement->GetText();
        }

        tinyxml2::XMLElement * StatusElement = itemElement->FirstChildElement("Status");
        if(StatusElement != nullptr){
            Status = StatusElement->GetText();
        }

        return 0;
    }

    int CataDevice::PrintInfo()
    {
        EyerLog("DeviceID: %s\n", DeviceID.str);
        EyerLog("Name: %s\n", Name.str);
        EyerLog("Manufacturer: %s\n", Manufacturer.str);
        EyerLog("Model: %s\n", Model.str);
        EyerLog("Owner: %s\n", Owner.str);
        EyerLog("CivilCode: %s\n", CivilCode.str);
        EyerLog("Address: %s\n", Address.str);
        EyerLog("Parental: %s\n", Parental.str);
        EyerLog("ParentID: %s\n", ParentID.str);
        EyerLog("SafetyWay: %s\n", SafetyWay.str);
        EyerLog("RegisterWay: %s\n", RegisterWay.str);
        EyerLog("Secrecy: %s\n", Secrecy.str);
        EyerLog("Status: %s\n", Status.str);
        return 0;
    }
}
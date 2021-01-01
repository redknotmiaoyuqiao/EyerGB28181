#include "EyerXMLCatalog.hpp"
#include "CataDevice.hpp"

/*
<Response>
    <CmdType>Catalog</CmdType>
    <SN>4</SN>
    <DeviceID>34020000001320000001</DeviceID>
    <SumNum>1</SumNum>
    <DeviceList Num="1">
        <Item>
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
        </Item>
    </DeviceList>
</Response>
*/

namespace Eyer
{
    int EyerXMLCatalog::ParseSub(tinyxml2::XMLElement * root)
    {
        tinyxml2::XMLElement * SumNumElement = root->FirstChildElement("SumNum");
        if(SumNumElement != nullptr){
            SumNum = SumNumElement->IntText();
        }

        tinyxml2::XMLElement * DeviceListElement = root->FirstChildElement("DeviceList");
        if(DeviceListElement != nullptr){
            for(tinyxml2::XMLElement * elem = DeviceListElement->FirstChildElement(); elem != nullptr; elem = elem->NextSiblingElement()) {
                tinyxml2::XMLElement * ItemElement = elem;
                if(ItemElement != nullptr){
                    CataDevice cataDevice;
                    cataDevice.Parse(ItemElement);
                    deviceList.AddDevice(cataDevice);
                }
            }
        }

        return 0;
    }
}
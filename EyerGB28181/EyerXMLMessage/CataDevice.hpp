#ifndef EYERGB28181_CATADEVICE_HPP
#define EYERGB28181_CATADEVICE_HPP

#include "EyerCore/EyerCore.hpp"
#include <tinyxml2.h>

namespace Eyer
{
    class CataDevice {
    public:
        CataDevice();
        CataDevice(const CataDevice & cataDevice);
        ~CataDevice();

        const CataDevice & operator = (const CataDevice & cataDevice);

        int Parse(tinyxml2::XMLElement * ItemElement);

        int PrintInfo();
    public:
        EyerString DeviceID;
        EyerString Name;
        EyerString Manufacturer;
        EyerString Model;
        EyerString Owner;
        EyerString CivilCode;
        EyerString Address;
        EyerString Parental;
        EyerString ParentID;
        EyerString SafetyWay;
        EyerString RegisterWay;
        EyerString Secrecy;
        EyerString Status;
    };
}

#endif //EYERGB28181_CATADEVICE_HPP

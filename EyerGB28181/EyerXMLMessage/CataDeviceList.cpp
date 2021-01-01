#include "CataDeviceList.hpp"

namespace Eyer
{
    CataDeviceList::CataDeviceList()
    {

    }

    CataDeviceList::~CataDeviceList()
    {
        for(int i=0;i<deviceList.size();i++){
            delete deviceList[i];
        }
        deviceList.clear();
    }

    CataDeviceList::CataDeviceList(const CataDeviceList & cataDeviceList)
    {
        *this = cataDeviceList;
    }

    const CataDeviceList & CataDeviceList::operator = (const CataDeviceList & cataDeviceList)
    {
        for(int i=0;i<cataDeviceList.deviceList.size();i++){
            CataDevice * deviceTemp = cataDeviceList.deviceList[i];
            CataDevice * device = new CataDevice(*deviceTemp);
            deviceList.push_back(device);
        }
        return *this;
    }

    int CataDeviceList::AddDevice(const CataDevice & cataDevice)
    {
        CataDevice * device = new CataDevice(cataDevice);
        deviceList.push_back(device);
        return 0;
    }

    int CataDeviceList::Size()
    {
        return deviceList.size();
    }

    int CataDeviceList::GetDevice(CataDevice & cataDevice, int i)
    {
        cataDevice = *deviceList[i];
        return 0;
    }
}
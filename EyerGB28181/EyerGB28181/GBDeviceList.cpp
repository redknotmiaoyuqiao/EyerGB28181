#include "GBDeviceList.hpp"

namespace Eyer
{
    GBDeviceList::GBDeviceList()
    {

    }

    GBDeviceList::~GBDeviceList()
    {
        for(int i=0;i<deviceList.size();i++){
            delete deviceList[i];
        }
        deviceList.clear();
    }

    int GBDeviceList::Size()
    {
        return deviceList.size();
    }

    int GBDeviceList::Get(GBDevice & device, int index)
    {
        if(index < 0){
            return -1;
        }
        if(index >= deviceList.size()){
            return -1;
        }
        device = *deviceList[index];
        return 0;
    }

    int GBDeviceList::AddDevice(GBDevice & device)
    {
        GBDevice * tempDevice = new GBDevice(device);
        deviceList.push_back(tempDevice);
        return 0;
    }
}
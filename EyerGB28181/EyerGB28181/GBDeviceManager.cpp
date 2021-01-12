#include "GBDeviceManager.hpp"

namespace Eyer
{
    GBDeviceManager::GBDeviceManager()
    {

    }

    GBDeviceManager::~GBDeviceManager()
    {
        for(int i=0;i<deviceList.size();i++){
            delete deviceList[i];
        }
        deviceList.clear();
    }

    int GBDeviceManager::Register(EyerString & deviceID, EyerString & ip, EyerString & port)
    {
        GBDevice * device = new GBDevice(deviceID, ip, port);
        deviceList.push_back(device);
        return 0;
    }

    int GBDeviceManager::Update(EyerString & deviceID, EyerString & ip, EyerString & port)
    {
        for(std::vector<GBDevice *>::iterator it=deviceList.begin(); it != deviceList.end();++it) {
            GBDevice * device = *it;
            if(device->GetDeviceID() == deviceID){
                device->UpdateIP_PORT(ip, port);
            }
        }
        return 0;
    }

    int GBDeviceManager::UnRegister(EyerString & deviceID)
    {
        for(std::vector<GBDevice *>::iterator it=deviceList.begin(); it != deviceList.end();) {
            GBDevice * device = *it;
            if(device->GetDeviceID() == deviceID){
                it = deviceList.erase(it);
                delete device;
            }
            else{
                ++it;
            }
        }
        return 0;
    }

    int GBDeviceManager::FindDevice(GBDevice & device, EyerString & deviceID)
    {
        int ret = -1;
        for(std::vector<GBDevice *>::iterator it=deviceList.begin(); it != deviceList.end(); ++it) {
            GBDevice * _device = *it;
            if(_device->GetDeviceID() == deviceID){
                device = *_device;
                ret = 0;
            }
        }
        return ret;
    }

    int GBDeviceManager::CopyDevices(GBDeviceList & gbDeviceList)
    {
        for(int i=0;i<deviceList.size();i++){
            GBDevice * device = deviceList[i];
            gbDeviceList.AddDevice(*device);
        }
        return 0;
    }
}
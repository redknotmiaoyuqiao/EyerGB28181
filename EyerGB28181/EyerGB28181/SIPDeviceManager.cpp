#include "SIPDeviceManager.hpp"

namespace Eyer
{
    SIPDeviceManager::SIPDeviceManager()
    {

    }

    SIPDeviceManager::~SIPDeviceManager()
    {
        for(int i=0;i<deviceList.size();i++){
            delete deviceList[i];
        }
        deviceList.clear();
    }

    int SIPDeviceManager::Register(EyerString & deviceID, EyerString & ip, EyerString & port)
    {
        GBDevice * device = new GBDevice(deviceID, ip, port);
        deviceList.push_back(device);
        return 0;
    }

    int SIPDeviceManager::UnRegister(EyerString & deviceID)
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

    int SIPDeviceManager::FindDevice(GBDevice & device, EyerString & deviceID)
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

    int SIPDeviceManager::CopyDevices(GBDeviceList & gbDeviceList)
    {
        for(int i=0;i<deviceList.size();i++){
            GBDevice * device = deviceList[i];
            gbDeviceList.AddDevice(*device);
        }
        return 0;
    }
}
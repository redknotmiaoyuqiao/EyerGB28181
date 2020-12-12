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
        SIPDevice * device = new SIPDevice(deviceID, ip, port);
        deviceList.push_back(device);
        return 0;
    }

    int SIPDeviceManager::UnRegister(EyerString & deviceID)
    {
        for(std::vector<SIPDevice *>::iterator it=deviceList.begin(); it!=deviceList.end();) {
            SIPDevice * device = *it;
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

    int SIPDeviceManager::FindDevice(SIPDevice & device, EyerString & deviceID)
    {
        int ret = -1;
        for(std::vector<SIPDevice *>::iterator it=deviceList.begin(); it!=deviceList.end();++it) {
            SIPDevice * _device = *it;
            if(_device->GetDeviceID() == deviceID){
                device = *_device;
                ret = 0;
            }
        }
        return ret;
    }
}
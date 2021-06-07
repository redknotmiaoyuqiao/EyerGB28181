#ifndef EYERLIB_SIPDEVICEMANAGER_HPP
#define EYERLIB_SIPDEVICEMANAGER_HPP

#include "EyerCore/EyerCore.hpp"
#include "GBDevice.hpp"
#include "GBDeviceList.hpp"
#include <vector>

namespace Eyer
{
    class GBDeviceManager {
    public:
        GBDeviceManager();
        ~GBDeviceManager();

        int Register(EyerString & deviceID, EyerString & ip, EyerString & port);
        int Update(EyerString & deviceID, EyerString & ip, EyerString & port);

        int UnRegister(EyerString & deviceID);

        int FindDevice(GBDevice & device, EyerString & deviceID);

        int CopyDevices(GBDeviceList & gbDeviceList);
    private:
        std::vector<GBDevice *> deviceList;
    };
}

#endif //EYERLIB_SIPDEVICEMANAGER_HPP

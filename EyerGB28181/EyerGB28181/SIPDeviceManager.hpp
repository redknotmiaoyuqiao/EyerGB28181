#ifndef EYERLIB_SIPDEVICEMANAGER_HPP
#define EYERLIB_SIPDEVICEMANAGER_HPP

#include "EyerCore/EyerCore.hpp"
#include "GBDevice.hpp"
#include <vector>

namespace Eyer
{
    class SIPDeviceManager {
    public:
        SIPDeviceManager();
        ~SIPDeviceManager();

        int Register(EyerString & deviceID, EyerString & ip, EyerString & port);
        int UnRegister(EyerString & deviceID);

        int FindDevice(GBDevice & device, EyerString & deviceID);

    private:
        std::vector<GBDevice *> deviceList;
    };
}

#endif //EYERLIB_SIPDEVICEMANAGER_HPP

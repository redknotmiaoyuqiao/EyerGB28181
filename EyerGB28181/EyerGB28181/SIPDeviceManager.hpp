#ifndef EYERLIB_SIPDEVICEMANAGER_HPP
#define EYERLIB_SIPDEVICEMANAGER_HPP

#include "EyerCore/EyerCore.hpp"
#include "SIPDevice.hpp"
#include <vector>

namespace Eyer
{
    class SIPDeviceManager {
    public:
        SIPDeviceManager();
        ~SIPDeviceManager();

        int Register(EyerString & deviceID, EyerString & ip, EyerString & port);
        int UnRegister(EyerString & deviceID);

        int FindDevice(SIPDevice & device, EyerString & deviceID);

    private:
        std::vector<SIPDevice *> deviceList;
    };
}

#endif //EYERLIB_SIPDEVICEMANAGER_HPP

#ifndef EYERLIB_SIPDEVICE_HPP
#define EYERLIB_SIPDEVICE_HPP

#include <string>
#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class SIPDevice {
    public:
        SIPDevice();
        SIPDevice(EyerString & deviceID, EyerString & ip, EyerString & port);
        ~SIPDevice();

        SIPDevice(const SIPDevice & device);
        SIPDevice & operator = (const SIPDevice & device);

        EyerString & GetDeviceID();
        EyerString & GetIP();
        EyerString & GetPort();

    private:
        EyerString deviceID;
        EyerString ip;
        EyerString port;
    };
}

#endif //EYERLIB_SIPDEVICE_HPP

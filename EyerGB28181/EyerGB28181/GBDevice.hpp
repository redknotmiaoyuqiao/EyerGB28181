#ifndef EYERLIB_SIPDEVICE_HPP
#define EYERLIB_SIPDEVICE_HPP

#include <string>
#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class GBDevice {
    public:
        GBDevice();
        GBDevice(EyerString & deviceID, EyerString & ip, EyerString & port);
        ~GBDevice();

        GBDevice(const GBDevice & device);
        GBDevice & operator = (const GBDevice & device);

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

#include "SIPDevice.hpp"

namespace Eyer
{
    SIPDevice::SIPDevice()
    {

    }

    SIPDevice::SIPDevice(EyerString & _deviceID, EyerString & _ip, EyerString & _port) : SIPDevice()
    {
        deviceID        = _deviceID;
        ip              = _ip;
        port            = _port;
    }

    SIPDevice::~SIPDevice()
    {

    }

    SIPDevice::SIPDevice(const SIPDevice & device)
    {
        *this = device;
    }

    SIPDevice & SIPDevice::operator = (const SIPDevice & device)
    {
        deviceID    = device.deviceID;
        ip          = device.ip;
        port        = device.port;

        return *this;
    }

    EyerString & SIPDevice::GetDeviceID()
    {
        return deviceID;
    }

    EyerString & SIPDevice::GetIP()
    {
        return ip;
    }

    EyerString & SIPDevice::GetPort()
    {
        return port;
    }
}
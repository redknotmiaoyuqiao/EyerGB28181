#include "GBDevice.hpp"

namespace Eyer
{
    GBDevice::GBDevice()
    {

    }

    GBDevice::GBDevice(EyerString & _deviceID, EyerString & _ip, EyerString & _port) : GBDevice()
    {
        deviceID        = _deviceID;
        ip              = _ip;
        port            = _port;
    }

    GBDevice::~GBDevice()
    {

    }

    GBDevice::GBDevice(const GBDevice & device)
    {
        *this = device;
    }

    GBDevice & GBDevice::operator = (const GBDevice & device)
    {
        deviceID    = device.deviceID;
        ip          = device.ip;
        port        = device.port;

        return *this;
    }

    EyerString & GBDevice::GetDeviceID()
    {
        return deviceID;
    }

    EyerString & GBDevice::GetIP()
    {
        return ip;
    }

    EyerString & GBDevice::GetPort()
    {
        return port;
    }
}
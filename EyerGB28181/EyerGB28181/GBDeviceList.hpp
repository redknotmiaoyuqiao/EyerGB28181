#ifndef EYERGB28181_GBDEVICELIST_HPP
#define EYERGB28181_GBDEVICELIST_HPP

#include "GBDevice.hpp"

namespace Eyer
{
    class GBDeviceList {
    public:
        GBDeviceList();
        ~GBDeviceList();

        int Size();
        int Get(GBDevice & device, int index);
    private:
        std::vector<GBDevice *> deviceList;
    };
}

#endif //EYERGB28181_GBDEVICELIST_HPP

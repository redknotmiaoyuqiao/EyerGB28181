#ifndef EYERGB28181_CATADEVICELIST_HPP
#define EYERGB28181_CATADEVICELIST_HPP

#include <vector>
#include "CataDevice.hpp"

namespace Eyer
{
    class CataDeviceList {
    public:
        CataDeviceList();
        ~CataDeviceList();

        CataDeviceList(const CataDeviceList & cataDeviceList);
        const CataDeviceList & operator = (const CataDeviceList & cataDeviceList);

        int AddDevice(const CataDevice & cataDevice);

        int Size();
        int GetDevice(CataDevice & cataDevice, int i);

    private:
        std::vector<CataDevice *> deviceList;
    };
}

#endif //EYERGB28181_CATADEVICELIST_HPP

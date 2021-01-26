#ifndef EYERGB28181_JNICATALOGCALLBACK_HPP
#define EYERGB28181_JNICATALOGCALLBACK_HPP

#include "EyerGB28181/EyerGB28181.hpp"

namespace Eyer
{
    class JNICatalogCallback : public CatalogCallback{
    public:
        virtual int OnCatalog(int status, CataDeviceList & cataDeviceList);
    };
}

#endif //EYERGB28181_JNICATALOGCALLBACK_HPP

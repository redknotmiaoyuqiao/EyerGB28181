#ifndef EYERGB28181_CATALOGCALLBACK_HPP
#define EYERGB28181_CATALOGCALLBACK_HPP

#include "ActiveCallback.hpp"
#include "EyerXMLMessage/EyerXMLMessage.hpp"

namespace Eyer
{
    class CatalogCallback : public ActiveCallback {
    public:
        virtual int OnCatalog(int status, CataDeviceList & cataDeviceList) = 0;
        virtual ActiveCallbackType GetType();
    };
}



#endif //EYERGB28181_CATALOGCALLBACK_HPP

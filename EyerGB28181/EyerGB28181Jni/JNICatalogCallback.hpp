#ifndef EYERGB28181_JNICATALOGCALLBACK_HPP
#define EYERGB28181_JNICATALOGCALLBACK_HPP

#include "EyerXMLMessage/CataDeviceList.hpp"
#include "EyerGB28181/Callback/CatalogCallback.hpp"
#include "JNIHeader.hpp"

namespace Eyer
{
    class JNICatalogCallback : public CatalogCallback{
    public:
        JNICatalogCallback(jobject _catalogCallbackJo);
        ~JNICatalogCallback();

        virtual int OnCatalog(int status, CataDeviceList & cataDeviceList);

    public:
        jobject catalogCallbackJo = nullptr;
    };
}

#endif //EYERGB28181_JNICATALOGCALLBACK_HPP

#ifndef EYERGB28181_JNICATALOGCALLBACK_HPP
#define EYERGB28181_JNICATALOGCALLBACK_HPP

#include "EyerXMLMessage/CataDeviceList.hpp"
#include "EyerGB28181/Callback/CatalogCallback.hpp"
#include "JNIHeader.hpp"

namespace Eyer
{
    class JNICatalogCallback : public CatalogCallback{
    public:
        JNICatalogCallback(jobject _catalogCallbackJo, jobject _catalogDeviceListJo);
        ~JNICatalogCallback();

        virtual int OnCatalog(int status, CataDeviceList & cataDeviceList);

    public:
        jobject catalogCallbackJo = nullptr;
        jobject catalogDeviceListJo = nullptr;
    };
}

#endif //EYERGB28181_JNICATALOGCALLBACK_HPP

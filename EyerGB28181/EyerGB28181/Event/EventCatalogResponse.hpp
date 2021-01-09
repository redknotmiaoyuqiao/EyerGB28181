#ifndef EYERGB28181_EVENTCATALOGRESPONSE_HPP
#define EYERGB28181_EVENTCATALOGRESPONSE_HPP

#include <EyerXMLMessage/CataDeviceList.hpp>
#include "GBEvent.hpp"

namespace Eyer
{
    class EventCatalogResponse : public GBEvent{
    public:
        EventCatalogResponse();
        ~EventCatalogResponse();

        EventCatalogResponse(const EventCatalogResponse & event);
        EventCatalogResponse & operator = (const EventCatalogResponse & event);

        virtual SIPEventType GetEventType();

        virtual int Do(struct eXosip_t * excontext, GBServerContext * context);

    public:
        CataDeviceList cataDeviceList;
        EyerString callId;
    };
}



#endif //EYERGB28181_EVENTCATALOGRESPONSE_HPP

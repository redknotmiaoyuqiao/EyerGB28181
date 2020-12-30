#ifndef EYERGB28181_EVENTCATALOGRESPONSE_HPP
#define EYERGB28181_EVENTCATALOGRESPONSE_HPP

#include "SIPEvent.hpp"

namespace Eyer
{
    class EventCatalogResponse : public SIPEvent{
    public:
        EventCatalogResponse();
        ~EventCatalogResponse();

        EventCatalogResponse(const EventCatalogResponse & event);
        EventCatalogResponse & operator = (const EventCatalogResponse & event);

        virtual SIPEventType GetEventType();

        virtual int Do(struct eXosip_t * excontext, SIPServerContext * context);
    };
}



#endif //EYERGB28181_EVENTCATALOGRESPONSE_HPP

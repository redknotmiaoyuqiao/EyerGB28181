#ifndef EYERGB28181_EVENTCATALOGREQUEST_HPP
#define EYERGB28181_EVENTCATALOGREQUEST_HPP

#include "Callback/CatalogCallback.hpp"
#include "GBEvent.hpp"

namespace Eyer
{
    class EventCatalogRequest : public GBEvent{
    public:
        EventCatalogRequest();
        ~EventCatalogRequest();

        EventCatalogRequest(const EventCatalogRequest & event);
        EventCatalogRequest & operator = (const EventCatalogRequest & event);

        virtual SIPEventType GetEventType();

        virtual int Do(struct eXosip_t * excontext, GBServerContext * context);

    public:
        EyerString deviceId;
        CatalogCallback * catalogCallback = nullptr;
    };
}

#endif //EYERGB28181_EVENTCATALOGREQUEST_HPP

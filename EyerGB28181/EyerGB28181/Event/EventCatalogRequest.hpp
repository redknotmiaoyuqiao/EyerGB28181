#ifndef EYERGB28181_EVENTCATALOGREQUEST_HPP
#define EYERGB28181_EVENTCATALOGREQUEST_HPP

#include "Callback/CatalogCallback.hpp"
#include "SIPEvent.hpp"

namespace Eyer
{
    class EventCatalogRequest : public SIPEvent{
    public:
        EventCatalogRequest();
        ~EventCatalogRequest();

        EventCatalogRequest(const EventCatalogRequest & event);
        EventCatalogRequest & operator = (const EventCatalogRequest & event);

        virtual SIPEventType GetEventType();

        virtual int Do(struct eXosip_t * excontext, SIPServerContext * context);

    public:
        EyerString deviceId;
        CatalogCallback * catalogCallback = nullptr;
    };
}

#endif //EYERGB28181_EVENTCATALOGREQUEST_HPP

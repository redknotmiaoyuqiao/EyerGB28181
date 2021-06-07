#include "GBEventType.hpp"

namespace Eyer
{
    GBEventType GBEventType::USER_REGISTER        (1, "USER_REGISTER");
    GBEventType GBEventType::DEVICE_HEART         (2, "DEVICE_HEART");
    GBEventType GBEventType::REALTIME_REQUEST     (3, "REALTIME_REQUEST");
    GBEventType GBEventType::REALTIME_RESPONSE    (4, "REALTIME_RESPONSE");
    GBEventType GBEventType::CATA_REQUEST         (5, "CATA_REQUEST");
    GBEventType GBEventType::CATA_RESPONSE        (6, "CATA_RESPONSE");

    GBEventType::GBEventType(int _val, EyerString _name)
    {
        val = _val;
        name = _name;
    }

    GBEventType::~GBEventType()
    {

    }

    GBEventType::GBEventType(const GBEventType & eventType)
    {
        *this = eventType;
    }

    GBEventType & GBEventType::operator = (const GBEventType & eventType)
    {
        val = eventType.val;
        name = eventType.name;
        return *this;
    }

    bool GBEventType::operator == (const GBEventType & eventType)
    {
        return val == eventType.val;
    }

    bool GBEventType::operator != (const GBEventType & eventType)
    {
        return !(*this == eventType);
    }

    EyerString & GBEventType::GetName()
    {
        return name;
    }
}
#include "SIPEventType.hpp"

namespace Eyer
{
    SIPEventType SIPEventType::USER_REGISTER        (1, "USER_REGISTER");
    SIPEventType SIPEventType::DEVICE_HEART         (2, "DEVICE_HEART");
    SIPEventType SIPEventType::REALTIME_REQUEST     (3, "REALTIME_REQUEST");
    SIPEventType SIPEventType::REALTIME_RESPONSE    (4, "REALTIME_RESPONSE");
    SIPEventType SIPEventType::CATA_REQUEST         (5, "CATA_REQUEST");
    SIPEventType SIPEventType::CATA_RESPONSE        (6, "CATA_RESPONSE");

    SIPEventType::SIPEventType(int _val, EyerString _name)
    {
        val = _val;
        name = _name;
    }

    SIPEventType::~SIPEventType()
    {

    }

    SIPEventType::SIPEventType(const SIPEventType & eventType)
    {
        *this = eventType;
    }

    SIPEventType & SIPEventType::operator = (const SIPEventType & eventType)
    {
        val = eventType.val;
        name = eventType.name;
        return *this;
    }

    bool SIPEventType::operator == (const SIPEventType & eventType)
    {
        return val == eventType.val;
    }

    bool SIPEventType::operator != (const SIPEventType & eventType)
    {
        return !(*this == eventType);
    }

    EyerString & SIPEventType::GetName()
    {
        return name;
    }
}
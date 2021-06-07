#ifndef EYERLIB_SIPEVENTTYPE_HPP
#define EYERLIB_SIPEVENTTYPE_HPP

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    enum SIPEventTarget
    {
        SIPEventTarget_MainThread,
        SIPEventTarget_EventThread,
        SIPEventTarget_Count
    };

    class GBEventType {
    public:
        GBEventType(int _val, EyerString _name);
        ~GBEventType();

        GBEventType(const GBEventType & eventType);
        GBEventType & operator = (const GBEventType & eventType);

        bool operator == (const GBEventType & eventType);
        bool operator != (const GBEventType & eventType);

        EyerString & GetName();

    private:
        int val;
        EyerString name;
    public:
        static GBEventType USER_REGISTER;
        static GBEventType DEVICE_HEART;

        static GBEventType REALTIME_REQUEST;
        static GBEventType REALTIME_RESPONSE;

        static GBEventType CATA_REQUEST;
        static GBEventType CATA_RESPONSE;
    };
}

#endif //EYERLIB_SIPEVENTTYPE_HPP

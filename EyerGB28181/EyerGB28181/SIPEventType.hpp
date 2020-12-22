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

    class SIPEventType {
    public:
        SIPEventType(int _val, EyerString _name);
        ~SIPEventType();

        SIPEventType(const SIPEventType & eventType);
        SIPEventType & operator = (const SIPEventType & eventType);

        bool operator == (const SIPEventType & eventType);
        bool operator != (const SIPEventType & eventType);

        EyerString & GetName();

    private:
        int val;
        EyerString name;
    public:
        static SIPEventType USER_REGISTER;
        static SIPEventType DEVICE_HEART;

        static SIPEventType REALTIME_REQUEST;
        static SIPEventType REALTIME_RESPONSE;

        static SIPEventType CATA_REQUEST;
        static SIPEventType CATA_RESPONSE;
    };
}

#endif //EYERLIB_SIPEVENTTYPE_HPP

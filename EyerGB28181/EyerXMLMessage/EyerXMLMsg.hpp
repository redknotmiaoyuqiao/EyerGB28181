#ifndef EYERGB28181_EYERXMLMSG_HPP
#define EYERGB28181_EYERXMLMSG_HPP

#include "EyerCore/EyerCore.hpp"
#include <tinyxml2.h>

namespace Eyer
{
    class EyerXMLMsg {
    public:
        EyerXMLMsg();
        ~EyerXMLMsg();

        int Parse(EyerString & xmlStr);

        virtual int ParseSub(tinyxml2::XMLElement * root);

        EyerString GetCMDType();

    public:
        EyerString cmdType;
        EyerString sn;
        EyerString DeviceID;
    };
}

#endif //EYERGB28181_EYERXMLMSG_HPP

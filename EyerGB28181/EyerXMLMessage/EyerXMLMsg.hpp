#ifndef EYERGB28181_EYERXMLMSG_HPP
#define EYERGB28181_EYERXMLMSG_HPP

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class EyerXMLMsg {
    public:
        EyerXMLMsg();
        ~EyerXMLMsg();

        int Parse(EyerString & xmlStr);

        EyerString GetCMDType();

    private:
        EyerString cmdType;
        EyerString sn;
    };
}

#endif //EYERGB28181_EYERXMLMSG_HPP

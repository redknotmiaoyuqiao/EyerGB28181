#ifndef EYERGB28181_EYERXMLCATALOG_HPP
#define EYERGB28181_EYERXMLCATALOG_HPP

#include "EyerXMLMsg.hpp"

namespace Eyer
{
    class EyerXMLCatalog : public EyerXMLMsg {
    public:
        virtual int ParseSub(tinyxml2::XMLElement * root);

    public:
        int SumNum = 0;
    };
}

#endif //EYERGB28181_EYERXMLCATALOG_HPP

#include "EyerXMLCatalog.hpp"

namespace Eyer
{
    int EyerXMLCatalog::ParseSub(tinyxml2::XMLElement * root)
    {
        tinyxml2::XMLElement * SumNumElement = root->FirstChildElement("SumNum");
        if(SumNumElement != nullptr){
            SumNum = SumNumElement->IntText();
        }

        return 0;
    }
}
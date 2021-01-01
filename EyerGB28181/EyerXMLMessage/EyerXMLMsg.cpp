#include "EyerXMLMsg.hpp"
#include <tinyxml2.h>

namespace Eyer
{
    EyerXMLMsg::EyerXMLMsg()
    {

    }

    EyerXMLMsg::~EyerXMLMsg()
    {

    }

    int EyerXMLMsg::Parse(EyerString & xmlStr)
    {
        // EyerLog("Xml: %s\n", xmlStr.str);

        tinyxml2::XMLDocument bodyDoc;
        bodyDoc.Parse(xmlStr.str, strlen(xmlStr.str));
        tinyxml2::XMLElement * root = bodyDoc.RootElement();
        // EyerLog("Root: %s\n", root->Name());
        if(root != nullptr){
            if(!root->NoChildren()){
                tinyxml2::XMLElement * CmdTypeElement = root->FirstChildElement("CmdType");
                if(CmdTypeElement != nullptr){
                    CmdType = CmdTypeElement->GetText();
                }

                tinyxml2::XMLElement * SNElement = root->FirstChildElement("SN");
                if(SNElement != nullptr){
                    SN = SNElement->GetText();
                }

                tinyxml2::XMLElement * DeviceIDElement = root->FirstChildElement("DeviceID");
                if(DeviceIDElement != nullptr){
                    DeviceID = DeviceIDElement->GetText();
                }

                ParseSub(root);
            }
        }

        return 0;
    }

    int EyerXMLMsg::ParseSub(tinyxml2::XMLElement * root)
    {
        return 0;
    }

    EyerString EyerXMLMsg::GetCMDType()
    {
        return CmdType;
    }
}
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
                // EyerLog("Root is not null !!!\n");
                tinyxml2::XMLElement * CmdTypeElement = root->FirstChildElement("CmdType");
                if(CmdTypeElement != nullptr){
                    cmdType = CmdTypeElement->GetText();
                    // EyerLog("CmdType: %s\n", cmdType.str);
                }

                tinyxml2::XMLElement * SNElement = root->FirstChildElement("SN");
                if(SNElement != nullptr){
                    sn = SNElement->GetText();
                    // EyerLog("sn: %s\n", sn.str);
                }
            }
        }

        return 0;
    }

    EyerString EyerXMLMsg::GetCMDType()
    {
        return cmdType;
    }
}
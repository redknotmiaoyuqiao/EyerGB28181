#include "EyerGBServer.hpp"

namespace Eyer
{
    EyerGBServer::EyerGBServer(int port)
    {
        sipServerThread = new EyerSIPServerThread(port);
    }

    EyerGBServer::~EyerGBServer()
    {
        if(sipServerThread != nullptr){
            sipServerThread->Stop();
            delete sipServerThread;
            sipServerThread = nullptr;
        }
    }

    int EyerGBServer::Start()
    {
        sipServerThread->Start();
        return 0;
    }

    int EyerGBServer::Stop()
    {
        sipServerThread->Stop();
        return 0;
    }
}
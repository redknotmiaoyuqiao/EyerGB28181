#include "EyerGBServer.hpp"

namespace Eyer
{
    EyerGBServer::EyerGBServer(int port)
    {
        sipServerThread = new EyerSIPServerThread(port);
        eventLoopThread = new EyerEventLoopThread();
    }

    EyerGBServer::~EyerGBServer()
    {
        if(sipServerThread != nullptr){
            sipServerThread->Stop();
            delete sipServerThread;
            sipServerThread = nullptr;
        }
        if(eventLoopThread != nullptr){
            eventLoopThread->Stop();
            delete eventLoopThread;
            eventLoopThread = nullptr;
        }
    }

    int EyerGBServer::Start()
    {
        eventLoopThread->Start();
        sipServerThread->Start();
        return 0;
    }

    int EyerGBServer::Stop()
    {
        sipServerThread->Stop();
        eventLoopThread->Stop();
        return 0;
    }
}
#include "EyerSIPServerThread.hpp"
#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    EyerSIPServerThread::EyerSIPServerThread(int port)
    {

    }

    EyerSIPServerThread::~EyerSIPServerThread()
    {

    }

    void EyerSIPServerThread::Run()
    {
        EyerLog("EyerSIPServerThread Start\n");

        while (!stopFlag){

        }

        EyerLog("EyerSIPServerThread End\n");
    }
}
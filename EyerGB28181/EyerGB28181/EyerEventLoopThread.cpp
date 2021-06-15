#include "EyerEventLoopThread.hpp"

namespace Eyer
{
    EyerEventLoopThread::EyerEventLoopThread()
    {

    }

    EyerEventLoopThread::~EyerEventLoopThread()
    {

    }

    void EyerEventLoopThread::Run()
    {
        EyerLog("EyerEventLoopThread Start\n");
        while(!stopFlag){

        }
        EyerLog("EyerEventLoopThread End\n");
    }
}
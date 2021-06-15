#include "EyerSIPServerThread.hpp"
#include "EyerCore/EyerCore.hpp"

#include "eXosipHeader.hpp"

namespace Eyer
{
    EyerSIPServerThread::EyerSIPServerThread(int _port)
    {
        port = _port;
    }

    EyerSIPServerThread::~EyerSIPServerThread()
    {

    }

    void EyerSIPServerThread::Run()
    {
        EyerLog("EyerSIPServerThread Start\n");

        int ret = 0;
        struct eXosip_t * excontext = eXosip_malloc();
        ret = eXosip_init(excontext);
        if (ret != 0) {
            EyerLog("Can't initialize eXosip!\n");
            return;
        }

        EyerLog("eXosip_init successfully!\n");

        while (!stopFlag){

        }

        EyerLog("EyerSIPServerThread End\n");
    }
}
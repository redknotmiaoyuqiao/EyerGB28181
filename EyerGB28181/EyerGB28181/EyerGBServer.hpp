#ifndef EYERGB28181_EYERGBSERVER_HPP
#define EYERGB28181_EYERGBSERVER_HPP

#include "EyerThread/EyerThread.hpp"
#include "EyerSIPServerThread.hpp"
#include "EyerEventLoopThread.hpp"

namespace Eyer
{
    class EyerGBServer
    {
    public:
        EyerGBServer(int port);
        ~EyerGBServer();

        int Start();
        int Stop();

    private:
        EyerSIPServerThread * sipServerThread = nullptr;
        EyerEventLoopThread * eventLoopThread = nullptr;
    };
}

#endif //EYERGB28181_EYERGBSERVER_HPP

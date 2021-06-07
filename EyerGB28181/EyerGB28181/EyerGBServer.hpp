#ifndef EYERGB28181_EYERGBSERVER_HPP
#define EYERGB28181_EYERGBSERVER_HPP

#include "EyerThread/EyerThread.hpp"
#include "EyerSIPServerThread.hpp"

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
    };
}

#endif //EYERGB28181_EYERGBSERVER_HPP

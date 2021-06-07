#ifndef EYERGB28181_EYERSIPSERVERTHREAD_HPP
#define EYERGB28181_EYERSIPSERVERTHREAD_HPP

#include "EyerThread/EyerThread.hpp"


namespace Eyer
{
    class EyerSIPServerThread : public EyerThread
    {
    public:
        EyerSIPServerThread(int port);
        ~EyerSIPServerThread();

        virtual void Run();
    };
}

#endif //EYERGB28181_EYERSIPSERVERTHREAD_HPP

#ifndef EYERLIB_SIPSERVERCONTEXT_HPP
#define EYERLIB_SIPSERVERCONTEXT_HPP

#include "GBDeviceManager.hpp"
#include "GBEventQueue.hpp"
#include "GBEventThread.hpp"
#include "PassiveCallback.hpp"
#include "ActiveCallbackList.hpp"

namespace Eyer
{
    class GBServerContext {
    public:
        GBServerContext();
        ~GBServerContext();

        GBDeviceManager deviceManager;
        GBEventQueue eventQueue;
        ActiveCallbackList activeCallbackList;
        GBEventThread * eventThread = nullptr;
        PassiveCallback * passiveCallback = nullptr;

        EyerString serverId = "34020000002000000001";
        EyerString serverRealm = "34020000";
    };
}

#endif //EYERLIB_SIPSERVERCONTEXT_HPP

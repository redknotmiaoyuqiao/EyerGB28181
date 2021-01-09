#ifndef EYERLIB_SIPSERVERCONTEXT_HPP
#define EYERLIB_SIPSERVERCONTEXT_HPP

#include "SIPDeviceManager.hpp"
#include "GBEventQueue.hpp"
#include "SIPEventThread.hpp"
#include "PassiveCallback.hpp"
#include "ActiveCallbackList.hpp"

namespace Eyer
{
    class GBServerContext {
    public:
        GBServerContext();
        ~GBServerContext();

        SIPDeviceManager deviceManager;
        GBEventQueue eventQueue;
        ActiveCallbackList activeCallbackList;
        SIPEventThread * eventThread = nullptr;
        PassiveCallback * passiveCallback = nullptr;

        EyerString serverId = "34020000002000000001";
        EyerString serverRealm = "34020000";
    };
}

#endif //EYERLIB_SIPSERVERCONTEXT_HPP

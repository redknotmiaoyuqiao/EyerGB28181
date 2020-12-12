#ifndef EYERLIB_SIPSERVERCONTEXT_HPP
#define EYERLIB_SIPSERVERCONTEXT_HPP

#include "SIPDeviceManager.hpp"
#include "SIPEventQueue.hpp"
#include "SIPEventThread.hpp"
#include "PassiveCallback.hpp"
#include "ActiveCallbackList.hpp"

namespace Eyer
{
    class SIPServerContext {
    public:
        SIPServerContext();
        ~SIPServerContext();

        SIPDeviceManager deviceManager;
        SIPEventQueue eventQueue;
        ActiveCallbackList activeCallbackList;
        SIPEventThread * eventThread = nullptr;
        PassiveCallback * passiveCallback = nullptr;

        EyerString serverId = "34020000002000000001";
        EyerString serverRealm = "34020000";
    };
}

#endif //EYERLIB_SIPSERVERCONTEXT_HPP

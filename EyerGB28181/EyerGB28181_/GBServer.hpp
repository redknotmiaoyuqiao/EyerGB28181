#ifndef EYERLIB_SIPSERVER_HPP
#define EYERLIB_SIPSERVER_HPP

#include "Callback/CatalogCallback.hpp"
#include "GBServerMainThread.hpp"
#include "GBServerContext.hpp"
#include "EyerCore/EyerCore.hpp"
#include "GBEventThread.hpp"
#include "ActiveCallbackList.hpp"
#include "GBDeviceList.hpp"

namespace Eyer
{
    class StartStreamCallback;
    class GBServer {
    public:
        GBServer(int _port = 5060);
        ~GBServer();

        int Start();
        int Stop();

        int SetCallback(PassiveCallback * callback);

        int GetDeviceList(GBDeviceList & gbDeviceList);

        int StartStream(
                const EyerString & streamServerIp,
                int streamServerPort,
                const EyerString & deviceId,
                StartStreamCallback * startStreamCallback);

        int StopStream(const EyerString & deviceId);

        int Catalog(EyerString deviceId, CatalogCallback * catalogCallback);

    private:
        int port = 5060;
        GBServerMainThread * mainThread = nullptr;
        GBServerContext context;
    };
}

#endif //EYERLIB_SIPSERVER_HPP

#include "GBServer.hpp"
#include "Event/EventStartRealTimeVideoRequest.hpp"
#include "Event/EventCatalogRequest.hpp"
#include "Event/EventCatalogResponse.hpp"
#include "Callback/StartStreamCallback.hpp"

namespace Eyer
{
    GBServer::GBServer(int _port)
    {
        port = _port;
    }

    GBServer::~GBServer()
    {
        Stop();
    }

    int GBServer::Start()
    {
        Stop();
        context.eventThread = new GBEventThread(&context);
        context.eventThread->Start();

        mainThread = new GBServerMainThread(port, &context);
        mainThread->Start();

        return 0;
    }

    int GBServer::Stop()
    {
        if(mainThread != nullptr){
            mainThread->Stop();
            delete mainThread;
            mainThread = nullptr;
        }
        if(context.eventThread != nullptr){
            context.eventThread->Stop();
            delete context.eventThread;
            context.eventThread = nullptr;
        }
        return 0;
    }

    int GBServer::SetCallback(PassiveCallback * callback)
    {
        context.passiveCallback = callback;
        return 0;
    }

    int GBServer::GetDeviceList(GBDeviceList & gbDeviceList)
    {
        context.deviceManager.CopyDevices(gbDeviceList);
        return 0;
    }

    int GBServer::StartStream(
            const EyerString & streamServerIp,
            int streamServerPort,
            const EyerString & deviceId,
            StartStreamCallback * startStreamCallback)
    {
        EventStartRealTimeVideoRequest * startRealTimeVideoRequest = new EventStartRealTimeVideoRequest();
        startRealTimeVideoRequest->streamServerIp       = streamServerIp;
        startRealTimeVideoRequest->streamServerPort     = streamServerPort;
        startRealTimeVideoRequest->deviceId             = deviceId;
        startRealTimeVideoRequest->channelId            = 0;
        startRealTimeVideoRequest->startStreamCallback  = startStreamCallback;
        context.eventQueue.PutEvent(startRealTimeVideoRequest);
        return 0;
    }

    int GBServer::StopStream(const EyerString & deviceId)
    {

        return 0;
    }

    int GBServer::Catalog(EyerString deviceId, CatalogCallback * catalogCallback)
    {
        EventCatalogRequest * catalogRequest = new EventCatalogRequest();
        catalogRequest->deviceId        = deviceId;
        catalogRequest->catalogCallback = catalogCallback;
        context.eventQueue.PutEvent(catalogRequest);
        return 0;
    }
}
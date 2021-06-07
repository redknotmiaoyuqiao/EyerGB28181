#include "Event/EventCatalogResponse.hpp"
#include "Event/EventDeviceHeart.hpp"
#include "Callback/StartStreamCallback.hpp"
#include "Event/EventStartRealTimeVideoResponse.hpp"
#include "GBEventThread.hpp"

#include "EyerCore/EyerCore.hpp"
#include "GBServerContext.hpp"
#include "Event/EventUserRegister.hpp"
#include "Callback/CatalogCallback.hpp"

namespace Eyer
{
    GBEventThread::GBEventThread(GBServerContext * _context)
    {
        context = _context;
    }

    GBEventThread::~GBEventThread()
    {
        while(context->eventQueue.Size() > 0){
            GBEvent * event = nullptr;
            context->eventQueue.GetEvent(&event);
            if(event != nullptr){
                delete event;
                event = nullptr;
            }
        }
    }

    void GBEventThread::Run()
    {
        while(!stopFlag){
            Eyer::EyerTime::EyerSleepMilliseconds(1);

            GBEvent * event = nullptr;
            context->eventQueue.GetEvent(&event);
            if(event != nullptr){
                if(event->to == SIPEventTarget::SIPEventTarget_EventThread){
                    GBEventType eventType = event->GetEventType();
                    if(eventType == GBEventType::USER_REGISTER){
                        if(context->passiveCallback != nullptr){
                            EventUserRegister * eventUserRegister = (EventUserRegister *)event;
                            context->passiveCallback->DeviceRegister(eventUserRegister->deviceId);
                        }
                    }
                    if(eventType == GBEventType::DEVICE_HEART){
                        if(context->passiveCallback != nullptr){
                            EventDeviceHeart * deviceHeart = (EventDeviceHeart *)event;
                            context->passiveCallback->DeviceHeart(deviceHeart->deviceId);
                        }
                    }
                    if(eventType == GBEventType::CATA_RESPONSE){
                        EventCatalogResponse * eventCatalogResponse = (EventCatalogResponse *)event;
                        EyerString callId = eventCatalogResponse->callId;
                        ActiveCallback * callback = nullptr;
                        context->activeCallbackList.FindCallback(&callback, callId);
                        if(callback != nullptr){
                            CatalogCallback * catelogCallback = (CatalogCallback *)callback;
                            catelogCallback->OnCatalog(0, eventCatalogResponse->cataDeviceList);
                        }
                    }
                    if(eventType == GBEventType::REALTIME_RESPONSE){
                        EventStartRealTimeVideoResponse * eventStartRealTimeVideoResponse = (EventStartRealTimeVideoResponse *)event;
                        EyerString callId = eventStartRealTimeVideoResponse->callId;
                        int status = eventStartRealTimeVideoResponse->status;
                        ActiveCallback * callback = nullptr;
                        context->activeCallbackList.FindCallback(&callback, callId);
                        if(callback != nullptr){
                            StartStreamCallback * startStreamCallback = (StartStreamCallback *)callback;
                            startStreamCallback->OnStartStream(status);
                        }
                    }

                    delete event;
                    event = nullptr;
                }
                else{
                    context->eventQueue.PutEvent(event);
                }
            }
        }
    }
}
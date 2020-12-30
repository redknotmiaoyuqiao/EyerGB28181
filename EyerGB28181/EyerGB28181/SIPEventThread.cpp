#include "Event/EventCatalogResponse.hpp"
#include "Event/EventDeviceHeart.hpp"
#include "Callback/StartStreamCallback.hpp"
#include "Event/EventStartRealTimeVideoResponse.hpp"
#include "SIPEventThread.hpp"

#include "EyerCore/EyerCore.hpp"
#include "SIPServerContext.hpp"
#include "Event/EventUserRegister.hpp"

namespace Eyer
{
    SIPEventThread::SIPEventThread(SIPServerContext * _context)
    {
        context = _context;
    }

    SIPEventThread::~SIPEventThread()
    {
        while(context->eventQueue.Size() > 0){
            SIPEvent * event = nullptr;
            context->eventQueue.GetEvent(&event);
            if(event != nullptr){
                delete event;
                event = nullptr;
            }
        }
    }

    void SIPEventThread::Run()
    {
        while(!stopFlag){
            Eyer::EyerTime::EyerSleepMilliseconds(1);

            SIPEvent * event = nullptr;
            context->eventQueue.GetEvent(&event);
            if(event != nullptr){
                if(event->to == SIPEventTarget::SIPEventTarget_EventThread){
                    SIPEventType eventType = event->GetEventType();
                    if(eventType == SIPEventType::USER_REGISTER){
                        if(context->passiveCallback != nullptr){
                            EventUserRegister * eventUserRegister = (EventUserRegister *)event;
                            context->passiveCallback->UserRegister(eventUserRegister->deviceId);
                        }
                    }
                    if(eventType == SIPEventType::DEVICE_HEART){
                        if(context->passiveCallback != nullptr){
                            EventDeviceHeart * deviceHeart = (EventDeviceHeart *)event;
                            context->passiveCallback->DeviceHeart(deviceHeart->deviceId);
                        }
                    }
                    if(eventType == SIPEventType::CATA_RESPONSE){
                        EventCatalogResponse * eventCatalogResponse = (EventCatalogResponse *)event;
                        EyerLog("CATA_RESPONSE\n");
                    }
                    if(eventType == SIPEventType::REALTIME_RESPONSE){
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
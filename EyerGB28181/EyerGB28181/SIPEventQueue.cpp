#include "SIPEventQueue.hpp"

namespace Eyer
{
    SIPEventQueue::SIPEventQueue()
    {

    }

    SIPEventQueue::~SIPEventQueue()
    {
        while(eventQueue.Size() > 0){
            SIPEvent * event = nullptr;
            eventQueue.FrontPop(&event);
            if(event != nullptr){
                delete event;
                event = nullptr;
            }
        }
    }

    int SIPEventQueue::PutEvent(SIPEvent * event)
    {
        eventQueue.Push(event);
        return 0;
    }

    int SIPEventQueue::GetEvent(SIPEvent ** event)
    {
        if(eventQueue.Size() <= 0){
            return -1;
        }
        eventQueue.FrontPop(event);
        return 0;
    }

    int SIPEventQueue::Size()
    {
        return eventQueue.Size();
    }
}
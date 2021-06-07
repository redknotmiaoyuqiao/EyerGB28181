#include "GBEventQueue.hpp"

namespace Eyer
{
    GBEventQueue::GBEventQueue()
    {

    }

    GBEventQueue::~GBEventQueue()
    {
        while(eventQueue.Size() > 0){
            GBEvent * event = nullptr;
            eventQueue.FrontPop(&event);
            if(event != nullptr){
                delete event;
                event = nullptr;
            }
        }
    }

    int GBEventQueue::PutEvent(GBEvent * event)
    {
        eventQueue.Push(event);
        return 0;
    }

    int GBEventQueue::GetEvent(GBEvent ** event)
    {
        if(eventQueue.Size() <= 0){
            return -1;
        }
        eventQueue.FrontPop(event);
        return 0;
    }

    int GBEventQueue::Size()
    {
        return eventQueue.Size();
    }
}
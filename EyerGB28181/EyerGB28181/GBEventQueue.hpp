#ifndef EYERLIB_SIPEVENTQUEUE_HPP
#define EYERLIB_SIPEVENTQUEUE_HPP

#include "EyerCore/EyerCore.hpp"
#include "GBEvent.hpp"

namespace Eyer
{
    class GBEventQueue {
    public:
        GBEventQueue();
        ~GBEventQueue();

        int PutEvent(GBEvent * event);
        int GetEvent(GBEvent ** event);

        int Size();
    private:
        EyerLockQueue<GBEvent> eventQueue;
    };
}

#endif //EYERLIB_SIPEVENTQUEUE_HPP

#ifndef EYERLIB_STARTSTREAMCALLBACK_HPP
#define EYERLIB_STARTSTREAMCALLBACK_HPP

#include "ActiveCallback.hpp"

namespace Eyer
{
    class StartStreamCallback : public ActiveCallback {
    public:
        virtual int OnStartStream(int status) = 0;
        virtual ActiveCallbackType GetType();
    };
}

#endif //EYERLIB_STARTSTREAMCALLBACK_HPP

#ifndef EYERLIB_CALLBACKLIST_HPP
#define EYERLIB_CALLBACKLIST_HPP

#include <vector>
#include "Callback/ActiveCallback.hpp"
#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class ActiveCallbackBean
    {
    public:
        ActiveCallback * callback = nullptr;
        EyerString callbackId;
    };

    class ActiveCallbackList
    {
    public:
        ActiveCallbackList();
        ~ActiveCallbackList();

        int PutCallback(ActiveCallback * callback, EyerString & callbackId);
        int FindCallback(ActiveCallback ** callback, EyerString & callbackId);
    private:
        std::vector<ActiveCallbackBean *> callbackList;
    };
}

#endif //EYERLIB_CALLBACKLIST_HPP

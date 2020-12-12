#include "ActiveCallbackList.hpp"

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    ActiveCallbackList::ActiveCallbackList()
    {

    }

    ActiveCallbackList::~ActiveCallbackList()
    {
        for(int i=0;i<callbackList.size();i++){
            delete callbackList[i];
        }
        callbackList.clear();
    }

    int ActiveCallbackList::PutCallback(ActiveCallback * activeCallback, EyerString & callbackId)
    {
        ActiveCallbackBean * callbackBean = new ActiveCallbackBean();
        callbackBean->callback = activeCallback;
        callbackBean->callbackId = callbackId;
        callbackList.push_back(callbackBean);
        return 0;
    }

    int ActiveCallbackList::FindCallback(ActiveCallback ** activeCallback, EyerString & callbackId)
    {
        int ret = -1;
        for(int i = 0; i < callbackList.size(); i++){
            ActiveCallbackBean * callbackBean = callbackList[i];
            if(callbackBean->callbackId == callbackId){
                *activeCallback = callbackBean->callback;
                ret = 0;
                break;
            }
        }
        return ret;
    }
}
#include "GBPlaybackSession.hpp"

namespace Eyer {
    GBPlaybackSession::GBPlaybackSession()
    {

    }

    GBPlaybackSession::GBPlaybackSession(int _callId, int _dialogId)
    {
        callId = _callId;
        dialogId = _dialogId;
    }

    GBPlaybackSession::~GBPlaybackSession()
    {

    }

    GBPlaybackSession::GBPlaybackSession(const GBPlaybackSession &session)
    {
        *this = session;
    }

    const GBPlaybackSession & GBPlaybackSession::operator=(const GBPlaybackSession &session){
        callId      = session.callId;
        dialogId    = session.dialogId;
        return *this;
    }
}
#ifndef EYERGB28181_GBPLAYBACKSESSION_HPP
#define EYERGB28181_GBPLAYBACKSESSION_HPP

namespace Eyer
{
    class GBPlaybackSession {
    public:
        GBPlaybackSession();
        GBPlaybackSession(int _callId, int _dialogId);
        ~GBPlaybackSession();

        GBPlaybackSession(const GBPlaybackSession & session);

        const GBPlaybackSession & operator = (const GBPlaybackSession & session);

    public:
        int callId      = -1;
        int dialogId    = -1;
    };
}


#endif //EYERGB28181_GBPLAYBACKSESSION_HPP

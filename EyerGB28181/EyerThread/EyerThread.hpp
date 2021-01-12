#ifndef	EYER_LIB_EYER_THREAD_H
#define	EYER_LIB_EYER_THREAD_H

#include <thread>
#include <mutex>
#include <atomic>
#include <queue>
#include <condition_variable>

namespace Eyer
{
    class EyerThread;
    class EyerRunnable;

    class EyerThread
    {
    public:
        EyerThread();
        ~EyerThread();

        int Start();
        int Stop();

        virtual void Run() = 0;
        virtual int BeforeStop();



        int PushEvent(EyerRunnable * event);

        int StartEventLoop();
        int StopEventLoop();

        int EventLoop();

    protected:
        std::atomic_int stopFlag {0};

        std::atomic_int eventLoopFlag {0};
        std::atomic_int eventLoopStatus {0};

        std::condition_variable cv;
        std::mutex cvMtx;

    private:
        std::thread * t = nullptr;
        std::queue<EyerRunnable *> eventQueue;
    };

    class EyerRunnable
    {
    public:
        virtual void Run() = 0;
    };
}

#endif
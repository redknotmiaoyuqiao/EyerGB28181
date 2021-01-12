#include "EyerThread.hpp"

#include <functional>

namespace Eyer
{
    EyerThread::EyerThread()
    {

    }

    EyerThread::~EyerThread()
    {
        Stop();

        while(eventQueue.size() > 0){
            EyerRunnable * event = eventQueue.front();
            eventQueue.pop();
        }
    }

    int EyerThread::Start()
    {
        if(t != nullptr){
            return -1;
        }

        stopFlag = 0;
        t = new std::thread(&EyerThread::Run, this);

        return 0;
    }

    int EyerThread::Stop()
    {
        if(t == nullptr){
            return -1;
        }

        stopFlag = 1;

        cv.notify_one();
        BeforeStop();

        if(t != nullptr){
            t->join();
            delete t;
            t = nullptr;
        }
        stopFlag = 0;

        return 0;
    }

    int EyerThread::BeforeStop()
    {
        return 0;
    }

    int EyerThread::PushEvent(EyerRunnable * event)
    {
        eventQueue.push(event);
        return 0;
    }


    int EyerThread::StartEventLoop()
    {
        eventLoopFlag = 1;
        while(1){
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if(eventLoopStatus == 1){
                break;
            }
        }
        return 0;
    }

    int EyerThread::StopEventLoop()
    {
        eventLoopFlag = 0;
        while(1){
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if(eventLoopStatus == 0){
                break;
            }
        }
        return 0;
    }

    int EyerThread::EventLoop()
    {
        if(!eventLoopFlag) {
            return -1;
        }

        eventLoopStatus = 1;

        while(eventQueue.size()) {
            EyerRunnable * runnable = eventQueue.front();
            eventQueue.pop();
            if(runnable != nullptr){
                runnable->Run();
            }
        }

        while(1) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if(eventLoopFlag == 0){
                break;
            }
        }

        eventLoopStatus = 0;

        return 0;
    }
}
#ifndef EYERLIB_EYERLOGTHREAD_HPP
#define EYERLIB_EYERLOGTHREAD_HPP

#include "EyerLogBean.hpp"
#include "EyerLockQueue.hpp"
#include "EyerThread/EyerThread.hpp"
#include "EyerLogParam.hpp"

namespace Eyer
{
    class EyerLogThread : public EyerThread
    {
    public:
        class GarbageCollector {
        public:
            ~GarbageCollector() {
                if (EyerLogThread::instance != nullptr) {
                    EyerLogThread::instance->Stop();
                    delete EyerLogThread::instance;
                    EyerLogThread::instance = nullptr;
                }
            }
        };
        static GarbageCollector gc;

        static EyerLogThread * instance;
        static EyerLogThread * GetInstance();

        EyerLogThread();
        ~EyerLogThread();

        virtual void Run();

        int SetLevel(int _level);

        int SetParam(EyerLogParam & param);

        int PutLog(EyerLogBean * logBean);

    private:
        EyerLockQueue<EyerLogBean> logQueue;
        int level = 5;

        int inline PrintLog(EyerLogBean * logBean);

        EyerLogParam param;
    };
}



#endif //EYERLIB_EYERLOGTHREAD_HPP

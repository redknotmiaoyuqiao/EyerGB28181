#include "EyerLogThread.hpp"
#include "EyerTime.hpp"

namespace Eyer
{
    EyerLogThread * EyerLogThread::instance = nullptr;

    EyerLogThread::GarbageCollector EyerLogThread::gc;

    EyerLogThread * EyerLogThread::GetInstance()
    {
        if(EyerLogThread::instance == nullptr){
            EyerLogThread::instance = new EyerLogThread();
            EyerLogThread::instance->Start();
        }
        return EyerLogThread::instance;
    }

    EyerLogThread::EyerLogThread()
    {

    }

    EyerLogThread::~EyerLogThread()
    {
        while(logQueue.Size() > 0){
            EyerLogBean * logBean = nullptr;
            logQueue.FrontPop(&logBean);
            if(logBean != nullptr){
                printf("%s", logBean->GetLog().str);

                delete logBean;
                logBean = nullptr;
            }
        }
    }

    void EyerLogThread::Run()
    {
        while(!stopFlag){
            EyerTime::EyerSleepMilliseconds(1);
            EyerLogBean * logBean = nullptr;
            logQueue.FrontPop(&logBean);
            if(logBean != nullptr){
                // printf("[%d] [%s (%d)] [%s] %s", logBean->GetLevel(), logBean->GetFile().str, logBean->GetLine(), logBean->GetFunction().str, logBean->GetLog().str);
                if(logBean->GetLevel() >= level){
                    PrintLog(logBean);
                }

                delete logBean;
                logBean = nullptr;
            }
        }

        while(logQueue.Size() > 0){
            EyerLogBean * logBean = nullptr;
            logQueue.FrontPop(&logBean);
            if(logBean != nullptr){
                if(logBean->GetLevel() >= level){
                    PrintLog(logBean);
                }

                delete logBean;
                logBean = nullptr;
            }
        }
    }

    int EyerLogThread::SetParam(EyerLogParam & _param)
    {
        param = _param;
        return 0;
    }

    int EyerLogThread::PrintLog(EyerLogBean * logBean)
    {
        std::string logstr;
        if(param.isLevel){
            char levelStr[8];
            sprintf(levelStr, "[%2d] ", logBean->GetLevel());
            logstr += levelStr;
        }
        if(param.isTime){
            logstr += "[" + std::string(logBean->GetTimeStr().str) + "] ";
        }
        if(param.isFile){
            logstr += "[" + std::string(logBean->GetFile().str) + "(" + std::to_string(logBean->GetLine()) + ")" + "] ";
        }
        if(param.isFunc){
            logstr += "[" + std::string(logBean->GetFunction().str) + "] ";
        }
        logstr += std::string(logBean->GetLog().str);
        printf("%s", logstr.c_str());
        return 0;
    }

    int EyerLogThread::PutLog(EyerLogBean * logBean)
    {
        logQueue.Push(logBean);
        return 0;
    }

    int EyerLogThread::SetLevel(int _level)
    {
        level = _level;
        return 0;
    }
}
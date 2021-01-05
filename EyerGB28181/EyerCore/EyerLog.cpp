#include "EyerLog.hpp"

#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <thread>
#include <stdarg.h>

#include "EyerLogThread.hpp"
#include "EyerLogBean.hpp"

int eyer_log_path(const char * path)
{
    Eyer::EyerLogThread * logThread = Eyer::EyerLogThread::GetInstance();
    return logThread->SetPath(path);
}

int eyer_log_set_level(int level)
{
    Eyer::EyerLogThread * logThread = Eyer::EyerLogThread::GetInstance();
    logThread->SetLevel(level);
    return 0;
}

int eye_log_set_level(int level)
{
    Eyer::EyerLogThread * logThread = Eyer::EyerLogThread::GetInstance();
    logThread->SetLevel(level);
    return 0;
}

int eyer_log_param (int isLevel, int isTime, int isFile, int isLine, int isFunc)
{
    Eyer::EyerLogParam param;
    param.isLevel = isLevel;
    param.isTime = isTime;
    param.isFunc = isFunc;
    param.isFile = isFile;
    param.isLine = isLine;

    Eyer::EyerLogThread * logThread = Eyer::EyerLogThread::GetInstance();
    logThread->SetParam(param);

    return 0;
}

void eyer_log_log(const char * file, const char * function, int line, int level, const char * format, ...)
{
    char logStr[4096];
    memset(logStr, 0, 4096);

    va_list args;
    va_start(args, format);
    vsnprintf(logStr, 4096, format, args);
    va_end(args);

    Eyer::EyerLogBean * logBean = new Eyer::EyerLogBean(file, function, line, level, logStr);

    Eyer::EyerLogThread * logThread = Eyer::EyerLogThread::GetInstance();
    logThread->PutLog(logBean);
}

int     eyer_log_clear          ()
{
    class ClearEyerRunnable : public Eyer::EyerRunnable
    {
    public:
        ClearEyerRunnable(Eyer::EyerLogThread * _logThread)
        {
            logThread = _logThread;
        }

        virtual void Run()
        {
            logThread->Clear();
        }
    private:
        Eyer::EyerLogThread * logThread = nullptr;
    };

    Eyer::EyerLogThread * logThread = Eyer::EyerLogThread::GetInstance();

    ClearEyerRunnable clearRunnable(logThread);

    logThread->PushEvent(&clearRunnable);
    logThread->StartEventLoop();
    logThread->StopEventLoop();

    return 0;
}

/*
void EyerPrintf(const char * file, const char * function, int line, int level, const char * _format, ...)
{
    time_t t;
    struct tm * lt;
    time (&t);
    lt = localtime (&t);

    // std::thread::id main_thread_id = std::this_thread::get_id();
    std::thread::id main_thread_id = std::this_thread::get_id();
    if(level == EYER_LOG_LEVEL_ERROR){
        BaseEyerLog ("[ ERROR ][%d-%02d-%02d %02d:%02d:%02d][%lld]", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, main_thread_id);
    }
    if(level == EYER_LOG_LEVEL_INFO){
        BaseEyerLog ("[ INFO  ][%d-%02d-%02d %02d:%02d:%02d][%lld]", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, main_thread_id);
    }
    if(level == EYER_LOG_LEVEL_WARNING){
        BaseEyerLog ("[WARNING][%d-%02d-%02d %02d:%02d:%02d][%lld]", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, main_thread_id);
    }

    char * format = (char *)_format;
    // BaseRedLog("[2019-12-12 12:34:25 102][1]");
    // BaseRedLog("\033[;31m%s (%d) \033[0m",file,line);
    BaseEyerLog("%s (%d) ", file, line);

    va_list ap;
    char *p;
    char *sval;
    int ival;
    double dval;
    long long llival;
    va_start(ap,_format);

    for(p=format;*p;p++)
    {
        if(*p!='%')
        {
            BaseEyerLog("%c", *p);
            continue;
        }
        switch(*++p)
        {
            case 'l':
            {
                if(*(++p) == 'l'){
                    if(*(++p) == 'd'){
                        llival = va_arg(ap,long long);
                        BaseEyerLog("%lld",llival);
                        break;
                    }
                }
            }
            case 'd':
                ival=va_arg(ap,int);
                BaseEyerLog("%d",ival);
                break;
            case 'u':
                ival=va_arg(ap,int);
                BaseEyerLog("%u",ival);
                break;
            case 'c':
                ival=va_arg(ap,int);
                BaseEyerLog("%c",ival);
                break;
            case 'f':
                dval=va_arg(ap,double);
                BaseEyerLog("%f",dval);
                break;
            case 's':
                sval=va_arg(ap,char *);
                BaseEyerLog("%s",sval);
                break;
            default:
                // putchar(*p);
                BaseEyerLog("%c", *p);
                break;
        }
    }
    va_end(ap);  //结束时清理工作
}
*/
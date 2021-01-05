#include <EyerCore/EyerLog.hpp>
#include "EyerJNIClazzLoader.hpp"

namespace Eyer
{
    EyerJNIClazzLoader * EyerJNIClazzLoader::instance = nullptr;

    EyerJNIClazzLoader * EyerJNIClazzLoader::GetInstance()
    {
        if(instance == nullptr){
            instance = new EyerJNIClazzLoader();
        }
        return instance;
    }

    EyerJNIClazzLoader::EyerJNIClazzLoader()
    {

    }

    EyerJNIClazzLoader::~EyerJNIClazzLoader()
    {

    }

    int EyerJNIClazzLoader::JNILoadClazz(JNIEnv * env)
    {
        jclass classLoaderClass = env->FindClass("com/zzsin/eyer/gb28181/CInterface");
        if(classLoaderClass == nullptr){
            EyerLog("classLoaderClass is nullptr\n");
            return -1;
        }

        jclazzloader = static_cast<jclass>(env->NewGlobalRef(classLoaderClass));

        EyerLog("classLoaderClass is not nullptr\n");

        return 0;
    }

    jclass EyerJNIClazzLoader::GetClazz()
    {
        return jclazzloader;
    }
}
#include "EyerJNIObject.hpp"

#include "EyerJNIEnvManager.hpp"

namespace Eyer
{
    EyerJNIObject::EyerJNIObject(const EyerJNIEnv & _env, const EyerString & _clazzName, const EyerString & _methodSig, ...) :
        env(_env)
    {
        clazzName = _clazzName;

        /*
        jclass clazz = env.env->FindClass(clazzName.str);
        if(clazz == nullptr){
            EyerLog("EyerJNIObject FindClass Fail\n");
            return;
        }
        */

        /*
        jclass clazz = Eyer::EyerJNIEnvManager::GetInstance()->FindClazz(clazzName.str);
        if(clazz == nullptr){
            EyerLog("EyerJNIObject FindClass Fail\n");
            return;
        }
        */

        clazz = Eyer::EyerJNIEnvManager::GetInstance()->FindClazz(clazzName.str);
        if(clazz == nullptr){
            EyerLog("EyerJNIObject FindClass Fail\n");
            return;
        }

        jmethodID init = env.env->GetMethodID(clazz, "<init>", _methodSig.str);
        if(init == nullptr){
            EyerLog("EyerJNIObject GetMethodID Fail\n");
            env.env->DeleteLocalRef(clazz);
            return;
        }

        va_list args;
        va_start(args, _methodSig);
        jobject clazzobj = env.env->NewObjectV(clazz, init, args);
        va_end(args);

        if(clazzobj == nullptr){
            EyerLog("EyerJNIObject NewObject Fail\n");
            env.env->DeleteLocalRef(clazz);
            return;
        }

        obj = env.env->NewGlobalRef(clazzobj);

        env.env->DeleteLocalRef(clazzobj);
    }

    EyerJNIObject::~EyerJNIObject()
    {
        if(obj != nullptr){
            env.env->DeleteGlobalRef(obj);
            obj = nullptr;
        }

        if(clazz != nullptr){
            env.env->DeleteLocalRef(clazz);
            clazz = nullptr;
        }
    }

    EyerJNIObject::EyerJNIObject(const EyerJNIObject & jniObject) :
        env(jniObject.env)
    {
        clazzName = jniObject.clazzName;
        clazz = Eyer::EyerJNIEnvManager::GetInstance()->FindClazz(clazzName.str);
        if(clazz == nullptr){
            EyerLog("EyerJNIObject FindClass Fail\n");
            return;
        }

        obj = env.env->NewGlobalRef(jniObject.obj);
    }

    int EyerJNIObject::CallInt(const EyerString & _methodName, const EyerString & _methodSig, ...)
    {
        /*
        jclass clazz = env.env->FindClass(clazzName.str);
        if(clazz == nullptr){
            EyerLog("EyerJNIObject FindClass Fail\n");
            return -1;
        }
        */
        /*
        jclass clazz = Eyer::EyerJNIEnvManager::GetInstance()->FindClazz(clazzName.str);
        if(clazz == nullptr){
            EyerLog("EyerJNIObject FindClass Fail\n");
            return -1;
        }
        */

        jmethodID methodId = env.env->GetMethodID(clazz, _methodName.str, _methodSig.str);
        if(methodId == nullptr){
            EyerLog("EyerJNIObject GetMethodID Fail\n");
            env.env->DeleteLocalRef(clazz);
            return -1;
        }

        va_list args;
        va_start(args, _methodSig);
        int ret = env.env->CallIntMethodV(obj, methodId, args);
        va_end(args);

        return ret;
    }
}
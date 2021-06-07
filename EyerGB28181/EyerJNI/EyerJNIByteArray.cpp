#include "EyerJNIByteArray.hpp"
#include "EyerJNIEnv.hpp"
#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    EyerJNIByteArray::EyerJNIByteArray(const EyerJNIEnv & _env, int len)
        :env(_env)
    {
        array = env.env->NewByteArray(len);

        jbyte bytekey[len];
        int bytekeylen = len;

        env.env->SetByteArrayRegion(array, 0, bytekeylen, bytekey);

        /*
        array = static_cast<jbyteArray>(env.env->NewGlobalRef(arrayTemp));
        env.env->DeleteLocalRef(arrayTemp);
         */
    }

    EyerJNIByteArray::~EyerJNIByteArray()
    {
        if(array != nullptr){
            env.env->DeleteLocalRef(array);
            // env.env->DeleteGlobalRef(array);
            array = nullptr;
        }
    }

    int EyerJNIByteArray::GetBuffer(uint8_t * buf)
    {
        int arrayLen = env.env->GetArrayLength(array);
        if(buf == nullptr){
            return arrayLen;
        }

        jbyte * c_array = env.env->GetByteArrayElements(array, 0);
        memcpy(buf, c_array, arrayLen);
        env.env->ReleaseByteArrayElements(array, c_array, 0);
        return 0;
    }
}
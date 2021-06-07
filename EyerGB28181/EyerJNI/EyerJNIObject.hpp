#ifndef EYERCAMERAANDROID_EYERJNIOBJECT_HPP
#define EYERCAMERAANDROID_EYERJNIOBJECT_HPP

#include "EyerJNIEnv.hpp"
#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class EyerJNIObject
    {
    public:
        EyerJNIObject(const EyerJNIEnv & _env, const EyerString & _clazzName, const EyerString & _methodSig, ...);
        ~EyerJNIObject();

        EyerJNIObject(const EyerJNIObject & jniObject);

        int CallInt(const EyerString & _methodName, const EyerString & _methodSig, ...);

    private:
        const EyerJNIObject & operator = (const EyerJNIObject & jniObject) = delete;

    public:
        EyerJNIEnv env;
        EyerString clazzName;

        jobject obj = nullptr;

        jclass clazz = nullptr;
    };
}

#endif //EYERCAMERAANDROID_EYERJNIOBJECT_HPP

#ifndef EYERCAMERAANDROID_EYERJNIBYTEARRAY_HPP
#define EYERCAMERAANDROID_EYERJNIBYTEARRAY_HPP

#include "EyerJNIEnv.hpp"

namespace Eyer
{
    class EyerJNIByteArray
    {
    public:
        EyerJNIByteArray(const EyerJNIEnv & _env, int len);
        ~EyerJNIByteArray();

        int GetBuffer(uint8_t * buf = nullptr);

    public:
        EyerJNIEnv env;
        jbyteArray array = nullptr;

    private:
        EyerJNIByteArray & operator = (const EyerJNIByteArray & byteArray) = delete;
        EyerJNIByteArray(const EyerJNIByteArray & byteArray) = delete;
    };
}

#endif //EYERCAMERAANDROID_EYERJNIBYTEARRAY_HPP

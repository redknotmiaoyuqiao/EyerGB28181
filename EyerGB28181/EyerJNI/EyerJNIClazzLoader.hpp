#ifndef EYERGB28181_EYERJNICLAZZLOADER_HPP
#define EYERGB28181_EYERJNICLAZZLOADER_HPP

#include "JNIHeader.hpp"

namespace Eyer
{
    class EyerJNIClazzLoader {
    public:
        static EyerJNIClazzLoader * GetInstance();
    private:
        static EyerJNIClazzLoader * instance;

    public:
        EyerJNIClazzLoader();
        ~EyerJNIClazzLoader();

        int JNILoadClazz(JNIEnv * env);

        jclass GetClazz();

    private:
        jclass jclazzloader = nullptr;
    };
}

#endif //EYERGB28181_EYERJNICLAZZLOADER_HPP

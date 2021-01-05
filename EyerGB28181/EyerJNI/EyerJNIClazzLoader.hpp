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
    };
}

#endif //EYERGB28181_EYERJNICLAZZLOADER_HPP

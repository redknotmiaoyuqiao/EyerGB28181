#ifndef EYERGB28181_EYERRAND_HPP
#define EYERGB28181_EYERRAND_HPP

#include "EyerString.hpp"

namespace Eyer {
    class EyerRand
    {
    public:
        static int Rand(int x);
        static EyerString RandNumberStr(int length);
    };
}

#endif //EYERGB28181_EYERRAND_HPP

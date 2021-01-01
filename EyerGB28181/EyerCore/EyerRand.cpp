#include "EyerMath.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "EyerRand.hpp"

namespace Eyer {
    int EyerRand::Rand(int x)
    {
        return (rand() * 1.0f / RAND_MAX) * x;
    }

    EyerString EyerRand::RandNumberStr(int length)
    {
        EyerString str;
        for(int i=0;i<length;i++){
            int num = Rand(10);
            if(num <= 0){
                num++;
            }
            str = str + EyerString::Number(num);
        }
        return str;
    }
}
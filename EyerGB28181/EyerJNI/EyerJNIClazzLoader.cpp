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
}
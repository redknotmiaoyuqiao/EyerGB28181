#include "EyerJNIEnvManager.hpp"

namespace Eyer
{
    JavaVM * EyerJNIEnvManager::vm = nullptr;

    EyerJNIEnvManager * EyerJNIEnvManager::instance = nullptr;

    EyerJNIEnvManager * EyerJNIEnvManager::GetInstance()
    {
        if(instance != nullptr){
            instance = new EyerJNIEnvManager();
        }
        return instance;
    }
}
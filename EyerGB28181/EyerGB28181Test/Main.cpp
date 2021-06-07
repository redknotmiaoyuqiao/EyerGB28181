#include "EyerGB28181/EyerGB28181.hpp"
#include "EyerCore/EyerCore.hpp"

Eyer::EyerGBServer * sipServer = nullptr;

int main(int argc, char **argv)
{
    eyer_log_param(1, 1, 1, 1, 0);

    sipServer = new Eyer::EyerGBServer(5060);
    sipServer->Start();

    for(int i = 0; i < 60 * 1; i++){
        Eyer::EyerTime::EyerSleepMilliseconds(1000);
    }
    sipServer->Stop();

    delete sipServer;

    return 0;
}
#include "EyerGB28181/EyerGB28181.hpp"
#include "EyerCore/EyerCore.hpp"

Eyer::SIPServer * sipServer = nullptr;

class MyPassiveCallback : public Eyer::PassiveCallback
{
public:
    virtual int UserRegister(Eyer::EyerString deviceId)
    {
        EyerLog("User Register Device Id: %s\n", deviceId.str);
        return 0;
    }

    virtual int DeviceHeart(Eyer::EyerString deviceId)
    {
        EyerLog("Device Heart Device Id: %s\n", deviceId.str);
        sipServer->Catalog(deviceId, nullptr);
        return 0;
    }
};

int main(int argc, char **argv)
{
    eyer_log_param(1, 1, 1, 1, 0);

    MyPassiveCallback passiveCallback;

    sipServer = new Eyer::SIPServer(5060);
    sipServer->SetCallback(&passiveCallback);
    sipServer->Start();

    for(int i = 0; i < 60 * 2; i++){
        Eyer::EyerTime::EyerSleepMilliseconds(1000);
    }

    sipServer->Stop();

    delete sipServer;

    return 0;
}
#include "EyerGB28181/EyerGB28181.hpp"
#include "EyerCore/EyerCore.hpp"

Eyer::GBServer * sipServer = nullptr;

class MyCatalogCallback : public Eyer::CatalogCallback
{
    virtual int OnCatalog(int status, Eyer::CataDeviceList & cataDeviceList)
    {
        EyerLog("OnCatalog\n");
        for(int i=0;i<cataDeviceList.Size();i++){
            Eyer::CataDevice cataDevice;
            cataDeviceList.GetDevice(cataDevice, i);
            // cataDevice.PrintInfo();
        }
        return 0;
    }
};

MyCatalogCallback * catalogCallback = nullptr;

class MyPassiveCallback : public Eyer::PassiveCallback
{
public:
    virtual int DeviceRegister(Eyer::EyerString deviceId)
    {
        EyerLog("User Register Device Id: %s\n", deviceId.str);
        sipServer->StartStream("39.105.183.99", 9000, deviceId, nullptr);
        return 0;
    }

    virtual int DeviceHeart(Eyer::EyerString deviceId)
    {
        EyerLog("Device Heart Device Id: %s\n", deviceId.str);
        sipServer->Catalog(deviceId, catalogCallback);
        return 0;
    }
};

int main(int argc, char **argv)
{
    eyer_log_param(1, 1, 1, 1, 0);

    catalogCallback = new MyCatalogCallback();

    MyPassiveCallback passiveCallback;

    sipServer = new Eyer::GBServer(5060);
    sipServer->SetCallback(&passiveCallback);
    sipServer->Start();

    for(int i = 0; i < 60 * 5; i++){
        Eyer::EyerTime::EyerSleepMilliseconds(1000);
    }

    sipServer->Stop();

    delete sipServer;
    delete catalogCallback;

    return 0;
}
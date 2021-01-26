#include "JNICatalogCallback.hpp"

namespace Eyer
{
    int JNICatalogCallback::OnCatalog(int status, CataDeviceList & cataDeviceList)
    {
        EyerLog("JNICatalogCallback OnCatalog status: %d\n", status);
        return 0;
    }
}
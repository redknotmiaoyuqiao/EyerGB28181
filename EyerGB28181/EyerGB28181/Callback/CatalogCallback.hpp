#ifndef EYERGB28181_CATALOGCALLBACK_HPP
#define EYERGB28181_CATALOGCALLBACK_HPP

#include "ActiveCallback.hpp"

namespace Eyer
{
    class CatalogCallback : public ActiveCallback {
    public:
        virtual int OnStartStream(int status) = 0;
        virtual ActiveCallbackType GetType();
    };
}



#endif //EYERGB28181_CATALOGCALLBACK_HPP

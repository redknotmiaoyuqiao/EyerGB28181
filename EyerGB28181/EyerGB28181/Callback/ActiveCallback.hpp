#ifndef EYERLIB_CALLBACK_HPP
#define EYERLIB_CALLBACK_HPP

namespace Eyer
{
    enum ActiveCallbackType
    {
        START_STREAM_CALLBACK,
        CATALOG_CALLBACK
    };

    class ActiveCallback {
    public:
        virtual ActiveCallbackType GetType() = 0;
    };
}

#endif //EYERLIB_CALLBACK_HPP

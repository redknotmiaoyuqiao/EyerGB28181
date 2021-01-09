include_directories (../)
include_directories (./)

add_library(
        EyerGB28181
        EyerGB28181.hpp
        GBServer.cpp
        GBServer.hpp
        GBServerMainThread.cpp
        GBServerMainThread.hpp
        eXosipHeader.hpp
        SIPProcess.cpp
        SIPProcess.hpp
        SIPProcessRegister.cpp
        SIPProcessRegister.hpp
        SIPProcessMessage.cpp
        SIPProcessMessage.hpp
        GBDevice.cpp
        GBDevice.hpp
        SIPDeviceManager.cpp
        SIPDeviceManager.hpp
        GBServerContext.cpp
        GBServerContext.hpp
        GBEventQueue.cpp
        GBEventQueue.hpp
        GBEvent.cpp
        GBEvent.hpp
        SIPEventThread.cpp
        SIPEventThread.hpp
        Event/EventUserRegister.cpp
        Event/EventUserRegister.hpp
        SIPEventType.cpp
        SIPEventType.hpp
        PassiveCallback.cpp
        PassiveCallback.hpp
        Event/EventStartRealTimeVideoRequest.cpp
        Event/EventStartRealTimeVideoRequest.hpp
        Event/EventStartRealTimeVideoResponse.cpp
        Event/EventStartRealTimeVideoResponse.hpp
        Callback/StartStreamCallback.cpp
        Callback/StartStreamCallback.hpp
        ActiveCallbackList.cpp
        ActiveCallbackList.hpp
        Callback/ActiveCallback.cpp
        Callback/ActiveCallback.hpp
        GBDeviceList.cpp
        GBDeviceList.hpp
        Event/EventDeviceHeart.cpp
        Event/EventDeviceHeart.hpp
        Callback/CatalogCallback.cpp
        Callback/CatalogCallback.hpp
        Event/EventCatalogRequest.cpp Event/EventCatalogRequest.hpp Event/EventCatalogResponse.cpp Event/EventCatalogResponse.hpp)

set(head_files
        EyerGB28181.hpp
        GBServer.hpp
        GBServerMainThread.hpp
        SIPProcess.hpp
        SIPProcessRegister.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerGB28181)
INSTALL(
        TARGETS EyerGB28181
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)


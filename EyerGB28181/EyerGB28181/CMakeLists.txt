include_directories (../)
include_directories (./)

add_library(
        EyerGB28181
        EyerGB28181.hpp
        SIPServer.cpp
        SIPServer.hpp
        SIPServerMainThread.cpp
        SIPServerMainThread.hpp
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
        SIPServerContext.cpp
        SIPServerContext.hpp
        SIPEventQueue.cpp
        SIPEventQueue.hpp
        SIPEvent.cpp
        SIPEvent.hpp
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
        GBDeviceList.cpp GBDeviceList.hpp Event/EventDeviceHeart.cpp Event/EventDeviceHeart.hpp)

set(head_files
        EyerGB28181.hpp
        SIPServer.hpp
        SIPServerMainThread.hpp
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


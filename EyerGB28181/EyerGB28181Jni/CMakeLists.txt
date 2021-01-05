include_directories (../)
include_directories (./)
include_directories (../EyerJNI)

add_library(
        EyerGB28181Jni
        SHARED
        CInterface.cpp
        JNIPassiveCallback.cpp
        JNIPassiveCallback.hpp
        CInterfaceDeviceList.cpp
        JNICatalog.cpp
        CJNITest.cpp
        TestThread.cpp
        TestThread.hpp
        JNICatalogCallback.cpp
        JNICatalogCallback.hpp
)

target_link_libraries (EyerGB28181Jni EyerGB28181)
target_link_libraries (EyerGB28181Jni EyerSIP)
target_link_libraries (EyerGB28181Jni EyerXMLMessage)
target_link_libraries (EyerGB28181Jni EyerJNI)
target_link_libraries (EyerGB28181Jni EyerCore)
target_link_libraries (EyerGB28181Jni EyerThread)
target_link_libraries (EyerGB28181Jni EyerJNI)

target_link_libraries (EyerGB28181Jni eXosip2)
target_link_libraries (EyerGB28181Jni osip2)
target_link_libraries (EyerGB28181Jni osipparser2)
target_link_libraries (EyerGB28181Jni tinyxml2)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")
    target_link_libraries (EyerGB28181Jni ssl)
    target_link_libraries (EyerGB28181Jni crypto)
    target_link_libraries (EyerGB28181Jni pthread)
    target_link_libraries (EyerGB28181Jni cares)
    target_link_libraries (EyerGB28181Jni resolv)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Android")
    MESSAGE(STATUS "current platform: Android")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    MESSAGE(STATUS "current platform: Darwin")
    target_link_libraries (EyerGB28181Jni resolv)
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

set(head_files

        )
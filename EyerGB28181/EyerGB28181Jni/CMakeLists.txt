include_directories (../)
include_directories (./)

add_library(
        EyerGB28181Jni
        SHARED
        CInterface.cpp
        JNIPassiveCallback.cpp JNIPassiveCallback.hpp)

target_link_libraries (EyerGB28181Jni EyerGB28181)
target_link_libraries (EyerGB28181Jni EyerSIP)
target_link_libraries (EyerGB28181Jni EyerCore)
target_link_libraries (EyerGB28181Jni EyerThread)
target_link_libraries (EyerGB28181Jni EyerJNI)

target_link_libraries (EyerGB28181Jni eXosip2)
target_link_libraries (EyerGB28181Jni osip2)
target_link_libraries (EyerGB28181Jni osipparser2)
target_link_libraries (EyerGB28181Jni resolv)

set(head_files

        )
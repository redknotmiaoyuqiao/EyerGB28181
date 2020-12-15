add_executable(
        EyerGB28181Test
        Main.cpp
)

include_directories (../)

target_link_libraries (EyerGB28181Test EyerGB28181)
target_link_libraries (EyerGB28181Test EyerSIP)
target_link_libraries (EyerGB28181Test EyerCore)
target_link_libraries (EyerGB28181Test EyerThread)

target_link_libraries (EyerGB28181Test eXosip2)
target_link_libraries (EyerGB28181Test osip2)
target_link_libraries (EyerGB28181Test osipparser2)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")
    target_link_libraries (EyerGB28181Test ssl)
    target_link_libraries (EyerGB28181Test crypto)
    target_link_libraries (EyerGB28181Test pthread)
    target_link_libraries (EyerGB28181Test cares)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Android")
    MESSAGE(STATUS "current platform: Android")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    MESSAGE(STATUS "current platform: Darwin")
    target_link_libraries (EyerGB28181Test resolv)
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

INSTALL(
        TARGETS EyerGB28181Test
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
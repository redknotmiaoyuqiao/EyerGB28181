include_directories (../)
include_directories (./)

add_library(
        EyerJNI
        EyerJNI.hpp

        EyerJNIEnv.hpp
        EyerJNIEnv.cpp

        EyerJNIObject.hpp
        EyerJNIObject.cpp

        EyerJNIEnvManager.hpp
        EyerJNIEnvManager.cpp

        EyerJNIByteArray.hpp
        EyerJNIByteArray.cpp
)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
        MESSAGE(STATUS "current platform: Linux")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
        MESSAGE(STATUS "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Android")
        MESSAGE(STATUS "current platform: Android")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
        MESSAGE(STATUS "current platform: Darwin")
ELSE ()
        MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

set(head_files
        EyerJNI.hpp
        EyerJNIEnv.hpp
        EyerJNIObject.hpp
        EyerJNIEnvManager.hpp
        EyerJNIByteArray.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerJNI)
INSTALL(
        TARGETS EyerJNI
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

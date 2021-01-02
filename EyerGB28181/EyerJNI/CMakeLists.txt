include_directories (../)
include_directories (./)

add_library(
        EyerJNI
        EyerJNI.cpp
        EyerJNIEnvManager.cpp
        EyerJNIClazzLoader.cpp EyerJNIClazzLoader.hpp)

set(head_files
        EyerJNI.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerJNI)
INSTALL(
        TARGETS EyerJNI
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)


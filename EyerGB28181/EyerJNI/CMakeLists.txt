include_directories (../)
include_directories (./)

add_library(
        EyerJNI
        EyerJNI.cpp
)

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


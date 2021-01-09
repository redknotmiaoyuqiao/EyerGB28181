include_directories (../)
include_directories (./)

add_library(
        EyerSIP
        EyerSIP.hpp
        EyerSIPMessgae.cpp
        EyerSIPMessgae.hpp
        EyerSIPMessgaePrivate.hpp
)

set(head_files
        EyerSIP.hpp
        EyerSIPMessgae.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerSIP)
INSTALL(
        TARGETS EyerSIP
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)


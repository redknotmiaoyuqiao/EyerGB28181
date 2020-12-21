include_directories (../)
include_directories (./)

add_library(
        EyerXMLMessage
        EyerXMLMessage.cpp
        EyerXMLMessage.hpp
        EyerXMLMsg.hpp
        EyerXMLMsg.cpp
)

set(head_files
        EyerXMLMessage.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerXMLMessage)
INSTALL(
        TARGETS EyerXMLMessage
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)


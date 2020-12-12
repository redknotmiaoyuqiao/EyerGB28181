include_directories (../)
include_directories (./)

add_library(
        EyerSIP
        EyerSIP.hpp
        EyerSIP.hpp
        EyerSIPMessgae.cpp
        EyerSIPMessgae.hpp
        EyerSIPMessgaePrivate.hpp
        EyerSIPFrom.cpp
        EyerSIPFrom.hpp
        EyerSIPFromPrivate.hpp
        EyerSIPCallID.cpp
        EyerSIPCallID.hpp
        EyerSIPCallIDPrivate.hpp
        EyerSIPCseq.cpp
        EyerSIPCseq.hpp
        EyerSIPCseqPrivate.hpp
        EyerSIPContact.cpp
        EyerSIPContact.hpp
        EyerSIPContactPrivate.hpp
        EyerSIPUri.cpp
        EyerSIPUri.hpp
        EyerSIPUriPrivate.hpp
)

set(head_files
        EyerSIP.hpp
        EyerSIPMessgae.hpp
        EyerSIPFrom.hpp
        EyerSIPCallID.hpp
        EyerSIPCseq.hpp
        EyerSIPContact.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerSIP)
INSTALL(
        TARGETS EyerSIP
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)


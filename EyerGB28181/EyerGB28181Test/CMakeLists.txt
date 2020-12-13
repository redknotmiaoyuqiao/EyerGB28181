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
target_link_libraries (EyerGB28181Test resolv)

INSTALL(
        TARGETS EyerGB28181Test
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
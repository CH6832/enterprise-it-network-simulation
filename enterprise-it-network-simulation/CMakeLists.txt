# CMakeList.txt : CMake project for enterprise-it-network-simulation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (enterprise-it-network-simulation "main.cpp"  "src/clients/notebook_client.cpp" "src/clients/smartphone_client.cpp" "tests/test_notebook_client.cpp" "tests/test_smartphone_client.cpp" "src/devices/computer_device.cpp" "src/devices/printer_device.cpp" "src/devices/router_device.cpp" "src/devices/firewall_device.cpp" "src/devices/file_server.cpp" "src/devices/web_server.cpp" "src/devices/database_server.cpp" "src/devices/mail_server.cpp" "src/devices/vpn_server.cpp" "tests/test_web_server.cpp" "tests/test_database_server.cpp" "tests/test_mail_server.cpp" "tests/test_vpn_server.cpp" "src/os_simulation/process_management.cpp" "src/os_simulation/file_system.cpp" "src/os_simulation/threading.cpp" "src/os_simulation/command_line_interface.cpp" "src/network/vpn_tunnel.cpp" "src/network/switch_device.cpp" "src/network/packets/tcp_packet.cpp" "src/network/packets/udp_packet.cpp" "src/network/packets/packet_handler.cpp" "src/network/routing/rip_routing.cpp" "src/network/routing/ospf_routing.cpp" "src/security/ids.cpp" "src/security/threat_detection.cpp" "src/security/encryption.cpp" "src/security/smurf_attack.cpp" "src/security/mitm_attack.cpp" "src/security/firewall/layer2_filter.cpp" "src/security/firewall/tcp_udp_limits.cpp" "src/security/firewall/qos_management.cpp" "src/security/firewall/vpn_encryption.cpp" "tests/test_packet_handler.cpp" "tests/test_vpn_tunnel.cpp" "tests/test_switch_device.cpp" "tests/test_ospf_routing.cpp" "tests/test_qos_management.cpp" "tests/test_encryption.cpp")

# Add this at the very beginning of the CMakeLists.txt
set(CMAKE_TOOLCHAIN_FILE "C:/Users/chris/vcpkg/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET enterprise-it-network-simulation PROPERTY CXX_STANDARD 20)
endif()

# Add the /utf-8 flag for MSVC compiler
if (MSVC)
    add_compile_options("/utf-8")
endif()

# Define paths for libraries based on the platform
if(WIN32)
    # Specify the paths to the libraries and includes for Windows
    set(LIB_PATH "C:/Users/chris/vcpkg/installed/x64-windows/lib")
    set(INCLUDE_PATH "C:/Users/chris/vcpkg/installed/x64-windows/include")
    set(BIN_PATH "C:/Users/chris/vcpkg/installed/x64-windows/bin")

    # Add include directories
    include_directories(${INCLUDE_PATH})

    # Specify the paths to the libraries
    set(LIBXML2_LIB_PATH "${LIB_PATH}/libxml2.lib")
    set(LIBICONV_LIB_PATH "${LIB_PATH}/iconv.lib")
    set(FMT_LIB_PATH "${LIB_PATH}/fmt.lib")
    set(GTEST_LIB_PATH "${LIB_PATH}/gtest.lib")
    set(ZLIB_LIB_PATH "${LIB_PATH}/zlib.lib")
    set(BOOST_FILESYSTEM_LIB_PATH "${LIB_PATH}/boost_filesystem-vc143-mt-x64-1_85.lib")
    set(BOOST_MOVE_LIB_PATH "${LIB_PATH}/boost_move-vc143-mt-x64-1_85.lib")

    # Link against Windows libraries
    target_link_libraries( enterprise-it-network-simulation PRIVATE 
        ${FMT_LIB_PATH} 
        ${LIBXML2_LIB_PATH} 
        ${LIBICONV_LIB_PATH} 
        ${GTEST_LIB_PATH} 
        ${ZLIB_LIB_PATH} 
        ${BOOST_FILESYSTEM_LIB_PATH}
    )

    # Copy necessary files to the output directory
    add_custom_command(TARGET enterprise-it-network-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/enterprise-it-network-simulation/input" 
        $<TARGET_FILE_DIR:enterprise-it-network-simulation>/input
    )

    # Copy DLLs to the output directory
    add_custom_command(TARGET enterprise-it-network-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/spdlog.dll" $<TARGET_FILE_DIR:enterprise-it-network-simulation>
    )
    add_custom_command(TARGET enterprise-it-network-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/fmt.dll" $<TARGET_FILE_DIR:enterprise-it-network-simulation>
    )
    add_custom_command(TARGET enterprise-it-network-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/libxml2.dll" $<TARGET_FILE_DIR:enterprise-it-network-simulation>
    )
    add_custom_command(TARGET enterprise-it-network-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/liblzma.dll" $<TARGET_FILE_DIR:enterprise-it-network-simulation>
    )
    add_custom_command(TARGET enterprise-it-network-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${BIN_PATH}/iconv-2.dll" $<TARGET_FILE_DIR:enterprise-it-network-simulation>
    )
    add_custom_command(TARGET enterprise-it-network-simulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${Boost_LIBRARY_DIRS}/*.dll" $<TARGET_FILE_DIR:enterprise-it-network-simulation>
    )

    # Enable Google Test
    enable_testing()

elseif(UNIX)  # This will match Linux/Unix systems
    # Specify the paths to the libraries and includes for UNIX
    set(LIB_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-linux/lib")
    set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-linux/include")

    # Add include directories
    include_directories(${INCLUDE_PATH})

    # Specify the paths to the libraries
    set(LIBXML2_LIB_PATH "${LIB_PATH}/libxml2.so")
    set(LIBICONV_LIB_PATH "${LIB_PATH}/libiconv.so")
    set(FMT_LIB_PATH "${LIB_PATH}/libfmt.so")
    set(BOOST_FILESYSTEM_LIB_PATH "${LIB_PATH}/libboost_filesystem.so")

    # Link against UNIX libraries
    target_link_libraries(xbrl-taxonomy-package-conformant-processor PRIVATE 
        ${FMT_LIB_PATH} 
        ${LIBXML2_LIB_PATH} 
        ${LIBICONV_LIB_PATH} 
        ${GTEST_LIB_PATH} 
        ${ZLIB_LIB_PATH} 
        ${BOOST_FILESYSTEM_LIB_PATH}
    )

    # Copy data.xml to the output directory
    add_custom_command(TARGET xbrl-taxonomy-package-conformant-processor POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/xbrl-taxonomy-package-conformant-processor/input" 
        $<TARGET_FILE_DIR:xbrl-taxonomy-package-conformant-processor>/input
    )
endif()

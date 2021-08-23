cmake_minimum_required(VERSION 3.16) 

project(DatagrandVNC)

# 生成unicode工程
add_definitions(-DUNICODE -D_UNICODE)

# 添加所有源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/ sourceList)

# 指定使用的头文件路径
# INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/)
# # 指定静态链接库路径pPp
# LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/)

# 设置变量 
SET(ALL_SRCS ${sourceList}) 
SET(ROOT_PATH ${PROJECT_SOURCE_DIR}/../../)

# # 设置可执行文件输出路径
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置DEBUG版本可执行文件输出路径        
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin/Debug)
# 设置RELEASE版本可执行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin/Release)

# # 设置库文件输出路径
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# # 设置DEBUG版本库文件输出路径
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/lib/Debug)
# # 设置RELEASE版本库文件输出路径
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/libtest)

# # 生成静态链接库
# ADD_LIBRARY(wsconfig-lib STATIC ${ALL_SRCS}) 
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)
set(MY_VERSIONINFO_RC "${PROJECT_SOURCE_DIR}/DatagrandVNC.rc")

# 将 DatagrandVNC.rc.in 中CMake变量都替换为当前CMake解析过程中的变量值
# if(MSVC)
#     set(MY_VERSIONINFO_RC "${CMAKE_BINARY_DIR}/DatagrandVNC.rc")
#     configure_file("${CMAKE_SOURCE_DIR}/DatagrandVNC.rc.in"
#                    "${MY_VERSIONINFO_RC }")
# endif()

ADD_EXECUTABLE(${PROJECT_NAME} WIN32 ${ALL_SRCS} ${MY_VERSIONINFO_RC})

# message("")
# target_include_directories(${PROJECT_NAME} PUBLIC ${ROOT_PATH}/include/)
# target_link_libraries(${PROJECT_NAME} PUBLIC
#   comctl32.lib
#   # ${ROOT_PATH}/lib/*.lib
#   ${ROOT_PATH}/lib/config-lib.lib
#   ${ROOT_PATH}/lib/desktop-ipc.lib
#   ${ROOT_PATH}/lib/desktop.lib
#   ${ROOT_PATH}/lib/fb-update-sender.lib
#   ${ROOT_PATH}/lib/file-lib.lib
#   ${ROOT_PATH}/lib/ft-common.lib
#   ${ROOT_PATH}/lib/ft-server-lib.lib
#   ${ROOT_PATH}/lib/Debug/gui.lib
#   ${ROOT_PATH}/lib/http-server-lib.lib
#   ${ROOT_PATH}/lib/io-lib.lib
#   ${ROOT_PATH}/lib/libjpeg.lib
#   ${ROOT_PATH}/lib/log-server.lib
#   ${ROOT_PATH}/lib/log-writer.lib
#   ${ROOT_PATH}/lib/network.lib
#   ${ROOT_PATH}/lib/region.lib
#   ${ROOT_PATH}/lib/rfb-sconn.lib
#   ${ROOT_PATH}/lib/rfb.lib
#   ${ROOT_PATH}/lib/screenhooks32.lib
#   ${ROOT_PATH}/lib/server-config-lib.lib
#   ${ROOT_PATH}/lib/tcp-dispatcher.lib
#   ${ROOT_PATH}/lib/thread.lib
#   ${ROOT_PATH}/lib/tvncontrol-app.lib
#   ${ROOT_PATH}/lib/tvnserver-app.lib
#   ${ROOT_PATH}/lib/util.lib
#   ${ROOT_PATH}/lib/win-event-log.lib
#   ${ROOT_PATH}/lib/win-system.lib
#   ${ROOT_PATH}/lib/wsconfig-lib.lib
#   ${ROOT_PATH}/lib/zlib.lib
# )

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS")


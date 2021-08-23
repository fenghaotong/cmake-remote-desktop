cmake_minimum_required(VERSION 3.16) 

project(wsconfig-lib)

# 生成unicode工程
add_definitions(-DUNICODE -D_UNICODE)

# 添加所有源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src/ sourceList)

# # 指定使用的头文件路径
# INCLUDE_DIRECTORIES(${ROOT_PATH}/include/)
# # 指定静态链接库路径
# LINK_DIRECTORIES(${ROOT_PATH}/lib/)

# 设置变量 
SET(ALL_SRCS ${sourceList}) 
SET(ROOT_PATH ${PROJECT_SOURCE_DIR}/../../)

# # 设置可执行文件输出路径
# set(EXECUTABLE_OUTPUT_PATH ${ROOT_PATH}/bin)

# # 设置DEBUG版本可执行文件输出路径
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${ROOT_PATH}/lib/Debug)
# # 设置RELEASE版本可执行文件输出路径
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${ROOT_PATH}/libtest)

# 设置库文件输出路径
# set(LIBRARY_OUTPUT_PATH ${ROOT_PATH}/lib)

# 设置DEBUG版本库文件输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${ROOT_PATH}/lib/Debug)
# 设置RELEASE版本库文件输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${ROOT_PATH}/lib/Release)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# 生成静态链接库
ADD_LIBRARY(${PROJECT_NAME} STATIC ${ALL_SRCS}) 

# target_include_directories(${PROJECT_NAME} PUBLIC ${ROOT_PATH}/include/)
# target_link_libraries(${PROJECT_NAME} PUBLIC
#   ${ROOT_PATH}/lib/config-lib.lib
#   ${ROOT_PATH}/lib/desktop-ipc.lib
#   ${ROOT_PATH}/lib/desktop.lib
#   ${ROOT_PATH}/lib/fb-update-sender.lib
#   ${ROOT_PATH}/lib/file-lib.lib
#   ${ROOT_PATH}/lib/ft-common.lib
#   ${ROOT_PATH}/lib/ft-server-lib.lib
#   ${ROOT_PATH}/lib/gui.lib
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
#   ${ROOT_PATH}/lib/zlib.lib
# )
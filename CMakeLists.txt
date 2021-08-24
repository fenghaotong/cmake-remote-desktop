cmake_minimum_required(VERSION 3.16) 

project(DatagrandVNC)

# 生成unicode工程
add_definitions(-DUNICODE -D_UNICODE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定使用的头文件路径
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/thirdlib/include/)
# # 指定静态链接库路径pPp
LINK_LIBRARIES(
  comctl32.lib
  ${PROJECT_SOURCE_DIR}/thirdlib/lib/Release/*.lib
)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# 添加子工程
ADD_SUBDIRECTORY(locallib/gui)
ADD_SUBDIRECTORY(locallib/wsconfig-lib)
ADD_SUBDIRECTORY(locallib/config-lib)
ADD_SUBDIRECTORY(locallib/desktop)
ADD_SUBDIRECTORY(locallib/desktop-ipc)
ADD_SUBDIRECTORY(locallib/fb-update-sender)
ADD_SUBDIRECTORY(locallib/file-lib)
ADD_SUBDIRECTORY(locallib/ft-common)
ADD_SUBDIRECTORY(locallib/ft-server-lib)
ADD_SUBDIRECTORY(locallib/http-server-lib)
ADD_SUBDIRECTORY(locallib/io-lib)
ADD_SUBDIRECTORY(locallib/libjpeg)
ADD_SUBDIRECTORY(locallib/log-server)
ADD_SUBDIRECTORY(locallib/log-writer)
ADD_SUBDIRECTORY(locallib/region)
ADD_SUBDIRECTORY(locallib/rfb)
ADD_SUBDIRECTORY(locallib/rfb-sconn)
ADD_SUBDIRECTORY(locallib/screen-hooks)
ADD_SUBDIRECTORY(locallib/server-config-lib)
ADD_SUBDIRECTORY(locallib/tcp-dispatcher)
ADD_SUBDIRECTORY(locallib/thread)
ADD_SUBDIRECTORY(locallib/tvncontrol-app)
# ADD_SUBDIRECTORY(locallib/network)
# ADD_SUBDIRECTORY(locallib/win-event-log)
# ADD_SUBDIRECTORY(locallib/tvnserver-app)
# ADD_SUBDIRECTORY(locallib/util)
# ADD_SUBDIRECTORY(locallib/win-system)
ADD_SUBDIRECTORY(locallib/zlib)
ADD_SUBDIRECTORY(src/main)
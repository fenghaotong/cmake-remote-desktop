cmake_minimum_required(VERSION 3.16) 

project(DatagrandVNC)

# 添加所有源文件
SET(MAIN_PATH ${PROJECT_SOURCE_DIR}/)
aux_source_directory(${MAIN_PATH}/ sourceList)

# 设置变量 
SET(ALL_SRCS ${sourceList}) 

# 设置DEBUG版本可执行文件输出路径        
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin/Debug)
# 设置RELEASE版本可执行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin/Release)

# 设置多线程调试模型
# set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# MFC设置
add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)
set(MY_VERSIONINFO_RC "${MAIN_PATH}/DatagrandVNC.rc")

ADD_EXECUTABLE(${PROJECT_NAME} WIN32 ${ALL_SRCS} ${MY_VERSIONINFO_RC})

# 添加依赖
add_dependencies(${PROJECT_NAME} 
  gui
  wsconfig-lib
  # config-lib
  # desktop
  # desktop-ipc
  # fb-update-sender
  # file-lib
  # ft-common
  # ft-server-lib
  # http-server-lib
  # io-lib
  # libjpeg
  # log-server
  # log-writer
  # region
  # rfb
  # rfb-sconn
  # screen-hooks
  # server-config-lib
  # tcp-dispatcher
  # thread
  # tvncontrol-app
  # zlib
  # network
  # tvnserver-app
  # win-event-log
  # util
  # win-system
)

# 设置子系统
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS")
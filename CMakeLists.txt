cmake_minimum_required(VERSION 3.16) 

project(DatagrandVNC)

# 生成unicode工程
add_definitions(-DUNICODE -D_UNICODE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定使用的头文件路径
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/thirdlib/include/)
# # 指定静态链接库路径pPp
LINK_LIBRARIES(
  comctl32.lib
  ${PROJECT_SOURCE_DIR}/thirdlib/lib/*.lib
  )

# 添加子工程
ADD_SUBDIRECTORY(locallib/gui)
ADD_SUBDIRECTORY(locallib/wsconfig-lib)

# 添加所有源文件
SET(MAIN_PATH ${PROJECT_SOURCE_DIR}/src/main/)
aux_source_directory(${MAIN_PATH}/ sourceList)

# 设置变量 
SET(ALL_SRCS ${sourceList}) 


# 设置DEBUG版本可执行文件输出路径        
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin/Debug)
# 设置RELEASE版本可执行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin/Release)

# 设置多线程调试模型
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# MFC设置
add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)
set(MY_VERSIONINFO_RC "${MAIN_PATH}/DatagrandVNC.rc")

ADD_EXECUTABLE(${PROJECT_NAME} WIN32 ${ALL_SRCS} ${MY_VERSIONINFO_RC})

# 添加依赖
add_dependencies(${PROJECT_NAME} gui wsconfig-lib)

# 设置子系统
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS")
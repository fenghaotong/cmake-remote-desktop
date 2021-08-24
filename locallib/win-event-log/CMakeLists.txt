cmake_minimum_required(VERSION 3.16) 

project(win-event-log)

# 生成unicode工程
add_definitions(-DUNICODE -D_UNICODE)

# 添加所有源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src/ sourceList1)

# 设置变量 
SET(ALL_SRCS ${sourceList1}) 
SET(ROOT_PATH ${PROJECT_SOURCE_DIR}/../../thirdlib/)

# 设置库文件输出路径
set(LIBRARY_OUTPUT_PATH ${ROOT_PATH}/lib)

# # 设置DEBUG版本库文件输出路径
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${ROOT_PATH}/lib/Debug)
# # 设置RELEASE版本库文件输出路径
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${ROOT_PATH}/lib/Release)

# MFC设置
add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)
set(MY_VERSIONINFO_RC "${PROJECT_SOURCE_DIR}/src/MessageProvider.rc")

# 生成静态链接库
ADD_LIBRARY(${PROJECT_NAME} STATIC ${ALL_SRCS} ${MY_VERSIONINFO_RC}) 


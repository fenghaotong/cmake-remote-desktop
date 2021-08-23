cmake_minimum_required(VERSION 3.16) 

project(datagrandVNC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定使用的头文件路径
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/)
# # 指定静态链接库路径pPp
LINK_LIBRARIES(
  comctl32.lib
  ${PROJECT_SOURCE_DIR}/lib/*.lib
  )


add_subdirectory(src/gui)
add_subdirectory(src/wsconfig-lib)
add_subdirectory(src/main)


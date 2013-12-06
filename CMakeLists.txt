project(tw_server_tracker)
cmake_minimum_required(VERSION 2.8)

#server
file(GLOB_RECURSE SRC_LIST "./server/include/twst/*" "./server/src/twst/*")
include_directories("./server/include")


add_executable(${PROJECT_NAME} ${SRC_LIST})
include_directories("external/mlk/include" "external/twl/include")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "-std=c++11")

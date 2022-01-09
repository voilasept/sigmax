cmake_minimum_required(VERSION 3.21)
project(sigmax)

set(CMAKE_CXX_STANDARD 17)

set(PATH_TO_GOOGLETEST /Users/hanchen/sigmax/googletest)
set(UNITEST_PATH /Users/hanchen/sigmax/unitests)

add_subdirectory(${PATH_TO_GOOGLETEST})
add_subdirectory(${UNITEST_PATH})

add_executable(sigmax main.cpp pool_mgr.h order.h common.h)


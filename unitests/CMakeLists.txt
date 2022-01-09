cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS " -Werror")

# --------------- GOOGLE TEST -----------------
# git clone as project subdirectory
#include googletest/include dir
include_directories(${PATH_TO_GOOGLETEST}/googletest/include)

#include the googlemock/include dir
include_directories(${PATH_TO_GOOGLETEST}/googlemock/include)
# ---------------------------------------------


include_directories(/usr/local/cpplib/boost)
include_directories(/usr/local/cpplib/fplus/FunctionalPlus/include)

add_executable(sigmax_tests test_order_pool.cpp)


# --------------- GOOGLE TEST -----------------
#Link with GoogleTest
target_link_libraries(sigmax_tests gtest gtest_main)

#Link with GoogleMock
target_link_libraries(sigmax_tests gmock gmock_main)
# ---------------------------------------------

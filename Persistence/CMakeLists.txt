cmake_minimum_required(VERSION 2.8)

project(CameraCalibrator C)

set(CMAKE_C_FLAGS_RELEASE "-Wall -Wextra -O2")

set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -g")

file(GLOB persistenceSrcs ${CMAKE_SOURCE_DIR}/Persistence/*.h*
                          ${CMAKE_SOURCE_DIR}/Persistence/*.cpp)

add_library(Persistence STATIC ${persistenceSrcs})

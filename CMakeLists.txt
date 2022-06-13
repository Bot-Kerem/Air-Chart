cmake_minimum_required(VERSION 3.23)

find_package(glfw3 REQUIRED)
find_package(assimp REQUIRED)
find_package(glm REQUIRED)

if(NOT Freetype_FOUND)
  #message(FATAL_ERROR "Freetype is required to build this project.")
endif()

if(NOT glfw3_FOUND)
  message(FATAL_ERROR "GLFW is required to build this project.")
endif()

set(LIB_GLAD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/glad/include)
set(LIB_GLAD_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

message(${LIB_GLAD_SOURCE_DIR}/glad/src/glad.c)

add_library(glad STATIC ${LIB_GLAD_SOURCE_DIR}/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glad/include)

set(LIB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)
set(LIB_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB LIB_SRCS ${LIB_SOURCE_DIR}/*.cpp)

add_library(AirChart STATIC ${LIB_SRCS})

target_include_directories(AirChart PUBLIC ${LIB_INCLUDE_DIR})
target_link_libraries(AirChart PUBLIC glfw freetype glm assimp glad)

# TEST
project(test)

set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SOURCES ${TEST_DIR}/test/*.cpp)

add_executable(test ${SOURCES})
target_link_libraries(test AirChart)
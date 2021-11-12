cmake_minimum_required(VERSION 3.16)
project(rtaudio_example
  DESCRIPTION "a example to learn rtaudio"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")

find_package(RtAudio REQUIRED)


include_directories(${PROJECT_INCLUDE_DIR})
include_directories(${RTAUDIO_INCLUDE_DIR})

set(MAIN_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
  )

add_executable(rtaudio_example
  ${MAIN_SOURCES})


target_link_libraries(rtaudio_example PRIVATE ${RTAUDIO_LIBRARIES})

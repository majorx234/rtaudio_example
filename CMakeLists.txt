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

set(SAW_WAVE_GENERATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/saw_wave_generator.cpp
  )

set(SQUARE_WAVE_GENERATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/square_wave_generator.cpp
  )

set(INVERSE_SAW_WAVE_GENERATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/inverse_saw_wave_generator.cpp
  )

set(TRIANGLE_WAVE_GENERATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/triangle_wave_generator.cpp
  )


set(PLOT_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/plot_wave.cpp
  )


add_executable(rtaudio_example
  ${MAIN_SOURCES})

add_executable(saw_wave_generator
  ${SAW_WAVE_GENERATOR_SOURCES})

add_executable(inverse_saw_wave_generator
  ${INVERSE_SAW_WAVE_GENERATOR_SOURCES})

add_executable(square_wave_generator
  ${SQUARE_WAVE_GENERATOR_SOURCES})

add_executable(triangle_wave_generator
  ${TRIANGLE_WAVE_GENERATOR_SOURCES})

add_executable(plot_wave
  ${PLOT_WAVE_SOURCES})

target_link_libraries(rtaudio_example PRIVATE ${RTAUDIO_LIBRARIES})

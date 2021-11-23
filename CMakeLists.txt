cmake_minimum_required(VERSION 3.16)
project(rtaudio_example
  DESCRIPTION "a example to learn rtaudio"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")

find_package(RtAudio REQUIRED)
find_package(PulseAudio REQUIRED)

include_directories(include)
include_directories(${PROJECT_INCLUDE_DIR})
include_directories(${RTAUDIO_INCLUDE_DIR})
include_directories(${PULSEAUDIO_INCLUDE_DIR})
message("test"${PULSEAUDIO_LIBRARY}" "${PULSEAUDIO_SIMPLE_LIBRARY})
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

set(TRIANGLE_WAVE_GENERATOR2_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/triangle_wave_generator2.cpp
  )

set(SINE_WAVE_GENERATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sine_wave_generator.cpp
  )

set(GEN_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gen_wave.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/gen_wave.h
)

set(SINE_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sine_wave.cpp
  )

set(GEN_WAVE_FACTORY_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gen_wave_factory.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/gen_wave_factory.h
	)

set(GEN_WAVE_EXAMPLE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gen_wave_example.cpp
)

set(PLOT_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/plot_wave.cpp
  )

set(PLOT2_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/plot2_wave.cpp
  )

set(ADSR_MODIFICATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/adsr_modificator.cpp
  )

set(PLAY_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/play_wave.cpp
  )


add_library(gen_wave
	${GEN_WAVE_SOURCES})

add_library(sine_wave
	${SINE_WAVE_SOURCES})

target_link_libraries(sine_wave
	gen_wave)

add_library(gen_wave_factory
	${GEN_WAVE_FACTORY_SOURCES})

target_link_libraries(gen_wave_factory
	sine_wave)

add_executable(gen_wave_example
  ${GEN_WAVE_EXAMPLE_SOURCES})

target_link_libraries(gen_wave_example
	gen_wave_factory
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

add_executable(triangle_wave_generator2
  ${TRIANGLE_WAVE_GENERATOR2_SOURCES})

add_executable(sine_wave_generator
  ${SINE_WAVE_GENERATOR_SOURCES})

add_executable(plot_wave
  ${PLOT_WAVE_SOURCES})

add_executable(plot2_wave
  ${PLOT2_WAVE_SOURCES})

add_executable(adsr_modificator
  ${ADSR_MODIFICATOR_SOURCES})

add_executable(play_wave
  ${PLAY_WAVE_SOURCES})

target_link_libraries(rtaudio_example PRIVATE ${RTAUDIO_LIBRARIES})
target_link_libraries(play_wave PRIVATE
	${PULSEAUDIO_LIBRARY}
	${PULSEAUDIO_SIMPLE_LIBRARY})

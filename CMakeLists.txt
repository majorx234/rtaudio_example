cmake_minimum_required(VERSION 3.16)
project(rtaudio_example
  DESCRIPTION "a example to learn rtaudio_cpp"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")

find_package(RtAudio REQUIRED)
find_package(PulseAudio REQUIRED)
find_package(SndFile REQUIRED)

include_directories(include)
include_directories(${PROJECT_INCLUDE_DIR})
include_directories(${RTAUDIO_INCLUDE_DIR})
include_directories(${PULSEAUDIO_INCLUDE_DIR})
include_directories(${SNDFILE_INCLUDE_DIR})

set(MAIN_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
  )

set(RTAUDIO_CPP_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/rtaudio/rtaudio.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/rtaudio.hpp
	)

set(SAW_WAVE_GENERATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/saw_wave_generator/saw_wave_generator.cpp
  )

set(SQUARE_WAVE_GENERATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/square_wave_generator/square_wave_generator.cpp
  )

set(INVERSE_SAW_WAVE_GENERATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/inverse_saw_wave_generator/inverse_saw_wave_generator.cpp
  )

set(TRIANGLE_WAVE_GENERATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/triangle_wave_generator/triangle_wave_generator.cpp
  )

set(TRIANGLE_WAVE_GENERATOR2_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/triangle_wave_generator2/triangle_wave_generator2.cpp
  )

set(SINE_WAVE_GENERATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sine_wave_generator/sine_wave_generator.cpp
  )

set(SAMPLE_WAVE_GENERATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sample_wave_generator/sample_wave_generator.cpp
  )

set(SINE_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sine_wave/sine_wave.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/sine_wave.hpp
  )

set(SAW_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/saw_wave/saw_wave.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/saw_wave.hpp
  )

set(INSAW_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/insaw_wave/insaw_wave.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/insaw_wave.hpp
  )

set(GEN_WAVE_FACTORY_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gen_wave_factory/gen_wave_factory.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/gen_wave_factory.hpp
	)

set(SAMPLE_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sample_wave/sample_wave.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/sample_wave.hpp
	)

set(TRI_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/tri_wave/tri_wave.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/tri_wave.hpp
	)

set(SINE_AMP_MOD_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sine_amp_mod_wave/sine_amp_mod_wave.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/sine_amp_mod_wave.hpp
  )


set(GEN_WAVE_EXAMPLE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/gen_wave_example/gen_wave_example.cpp
)

set(PLOT_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/plot_wave/plot_wave.cpp
  )

set(PLOT2_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/plot2_wave/plot2_wave.cpp
  )

set(ADSR_MODIFICATOR_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/adsr_modificator/adsr_modificator.cpp
  )

set(PLAY_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/play_wave/play_wave.cpp
  )

set(RTPLAY_WAVE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/rtplay_wave/rtplay_wave.cpp
  )

add_library(rtaudio_cpp)
target_sources(rtaudio_cpp
  PRIVATE
  ${RTAUDIO_CPP_SOURCES}
)
target_include_directories(rtaudio_cpp
  PRIVATE
  include
)

add_library(sine_wave)
target_sources(sine_wave
  PRIVATE
  ${SINE_WAVE_SOURCES}
)
target_include_directories(sine_wave
  PRIVATE
  include
)
target_link_libraries(sine_wave
  rtaudio_cpp
)

add_library(saw_wave)
target_sources(saw_wave
  PRIVATE
  ${SAW_WAVE_SOURCES}
)
target_include_directories(saw_wave
  PRIVATE
  include
)
target_link_libraries(saw_wave
  rtaudio_cpp
)

add_library(insaw_wave)
target_sources(insaw_wave
  PRIVATE
  ${INSAW_WAVE_SOURCES}
)
target_include_directories(insaw_wave
  PRIVATE
  include
)

add_library(tri_wave)
target_sources(tri_wave
  PRIVATE
  ${TRI_WAVE_SOURCES}
)
target_include_directories(tri_wave
  PRIVATE
  include
)

add_library(sample_wave)
target_sources(sample_wave
  PRIVATE
  ${SAMPLE_WAVE_SOURCES})
target_include_directories(sample_wave
  PRIVATE
  include
)
target_link_libraries(sample_wave
  PRIVATE SndFile::SndFile
)

add_library(sine_amp_mod_wave)
target_sources(sine_amp_mod_wave
  PRIVATE
  ${SINE_AMP_MOD_WAVE_SOURCES}
)
target_include_directories(sine_amp_mod_wave
  PRIVATE
  include
)

add_library(gen_wave_factory)
target_sources(gen_wave_factory
  PRIVATE
  ${GEN_WAVE_FACTORY_SOURCES}
)
target_include_directories(gen_wave_factory
  PRIVATE
  include
)
target_link_libraries(gen_wave_factory
  sine_wave
  saw_wave
  tri_wave
  sample_wave
  insaw_wave
  sine_amp_mod_wave
)

add_executable(gen_wave_example)
target_sources(gen_wave_example
  PRIVATE
  ${GEN_WAVE_EXAMPLE_SOURCES}
)
target_include_directories(gen_wave_example
  PRIVATE
  include
)
target_link_libraries(gen_wave_example
  gen_wave_factory
)

add_executable(rtaudio_example)
target_sources(rtaudio_example
  PRIVATE
  ${MAIN_SOURCES}
)
target_include_directories(rtaudio_example
  PRIVATE
  include
)
target_link_libraries(rtaudio_example
  PRIVATE
  ${RTAUDIO_LIBRARIES}
)

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

add_executable(sample_wave_generator
  ${SAMPLE_WAVE_GENERATOR_SOURCES})

target_link_libraries(sample_wave_generator PRIVATE SndFile::SndFile)

add_executable(plot_wave
  ${PLOT_WAVE_SOURCES})

add_executable(plot2_wave
  ${PLOT2_WAVE_SOURCES})

add_executable(adsr_modificator)
target_sources(adsr_modificator
  PRIVATE
  ${ADSR_MODIFICATOR_SOURCES}
)
target_include_directories(adsr_modificator
  PRIVATE
  include)
target_link_libraries(adsr_modificator
  rtaudio_cpp
)

add_executable(rtplay_wave)
target_sources(rtplay_wave
  PRIVATE
  ${RTPLAY_WAVE_SOURCES}
)
target_include_directories(rtplay_wave
  PRIVATE
  include
  ${RTAUDIO_INCLUDE_DIR}
)
target_link_libraries(rtplay_wave
  PRIVATE
  rtaudio_cpp
  ${RTAUDIO_LIBRARIES}
)

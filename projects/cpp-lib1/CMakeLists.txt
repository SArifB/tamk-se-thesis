option(THESIS_BUILD_CPP_LIB1 "Build cpp-lib1" FALSE)
if(NOT THESIS_BUILD_CPP_LIB1)
  message(STATUS "Build option not set, ignoring build (project: cpp-lib1)")
  return()
endif()

if(EMSCRIPTEN)
  message(FATAL_ERROR "Emscripten system found, impossible build (project: cpp-lib1)")
elseif(SKBUILD)
  message(FATAL_ERROR "SKBuild system found, impossible build (project: cpp-lib1)")
endif()

add_library(cpp-lib1 STATIC)
add_library(thesis::cpp-lib1 ALIAS cpp-lib1)
target_sources(cpp-lib1
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS src
    FILES
      src/thesis/cpp-lib1/append-to-upper.hpp
      src/thesis/cpp-lib1/to-upper-appender.hpp
  PRIVATE
    src/thesis/cpp-lib1/append-to-upper.cpp
)
target_compile_options(cpp-lib1 PRIVATE
  -Wall
  -Werror
  -Wextra
  -Wpedantic
)
set_target_properties(cpp-lib1 PROPERTIES
  CXX_EXTENSIONS OFF
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED ON
)

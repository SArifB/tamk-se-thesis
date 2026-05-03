option(THESIS_BUILD_C_LIB1 "Build c-lib1" FALSE)
if(NOT THESIS_BUILD_C_LIB1)
  message(STATUS "Build option not set, ignoring build (project: c-lib1)")
  return()
endif()

if(EMSCRIPTEN)
  message(FATAL_ERROR "Emscripten system found, impossible build (project: c-lib1)")
elseif(SKBUILD)
  message(FATAL_ERROR "SKBuild system found, impossible build (project: c-lib1)")
endif()

add_library(c-lib1 STATIC)
add_library(thesis::c-lib1 ALIAS c-lib1)
target_sources(c-lib1
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS src
    FILES
      src/thesis/c-lib1/to-upper.h
  PRIVATE
    src/thesis/c-lib1/to-upper.c
)
target_compile_options(c-lib1 PRIVATE
  -Wall
  -Werror
  -Wextra
  -Wpedantic
)
set_target_properties(c-lib1 PROPERTIES
  C_EXTENSIONS OFF
  C_STANDARD 23
  C_STANDARD_REQUIRED ON
)

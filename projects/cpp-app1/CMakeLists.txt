option(THESIS_BUILD_CPP_APP1 "Build cpp-app1" FALSE)
if(NOT THESIS_BUILD_CPP_APP1)
  message(STATUS "Build option not set, ignoring build (project: cpp-app1)")
  return()
endif()

if(EMSCRIPTEN)
  message(FATAL_ERROR "Emscripten system found, impossible build (project: cpp-app1)")
elseif(SKBUILD)
  message(FATAL_ERROR "SKBuild system found, impossible build (project: cpp-app1)")
endif()

add_executable(cpp-app1)
target_sources(cpp-app1
  PRIVATE
    FILE_SET HEADERS
    BASE_DIRS src
    FILES
      src/thesis/cpp-app1/my-print.hpp
  PRIVATE
    src/thesis/cpp-app1/main.cpp
    src/thesis/cpp-app1/my-print.cpp
)
target_compile_options(cpp-app1 PRIVATE
  -Wall
  -Werror
  -Wextra
  -Wpedantic
)
set_target_properties(cpp-app1 PROPERTIES
  CXX_EXTENSIONS OFF
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED ON
)
target_link_libraries(cpp-app1 PRIVATE
  thesis::cpp-lib1
)
install(
  TARGETS cpp-app1
  EXPORT cpp-app1
)

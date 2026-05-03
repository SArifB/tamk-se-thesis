option(THESIS_BUILD_CPP_APP3 "Build cpp-app3" FALSE)
if(NOT THESIS_BUILD_CPP_APP3)
  message(STATUS "Build option not set, ignoring build (project: cpp-app3)")
  return()
endif()

if(EMSCRIPTEN)
  message(FATAL_ERROR "Emscripten system found, impossible build (project: cpp-app3)")
elseif(SKBUILD)
  message(FATAL_ERROR "SKBuild system found, impossible build (project: cpp-app3)")
endif()

add_executable(cpp-app3)
target_sources(cpp-app3 PRIVATE
  src/thesis/cpp-app3/main.cpp
)
target_compile_options(cpp-app3 PRIVATE
  -Wall
  -Werror
  -Wextra
  -Wpedantic
)
set_target_properties(cpp-app3 PROPERTIES
  CXX_EXTENSIONS OFF
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED ON
)
target_link_libraries(cpp-app3 PRIVATE
  thesis::rust-lib1
  thesis::cpp-lib2
)
install(
  TARGETS cpp-app3
  EXPORT cpp-app3
)

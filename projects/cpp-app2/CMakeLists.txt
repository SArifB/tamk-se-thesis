option(THESIS_BUILD_CPP_APP2 "Build cpp-app2" FALSE)
if(NOT THESIS_BUILD_CPP_APP2)
  message(STATUS "Build option not set, ignoring build (project: cpp-app2)")
  return()
endif()

if(EMSCRIPTEN)
  message(FATAL_ERROR "Emscripten system found, impossible build (project: cpp-app2)")
elseif(SKBUILD)
  message(FATAL_ERROR "SKBuild system found, impossible build (project: cpp-app2)")
endif()

add_executable(cpp-app2)
target_sources(cpp-app2 PRIVATE
  src/thesis/cpp-app2/main.cpp
)
target_compile_options(cpp-app2 PRIVATE
  -Wall
  -Werror
  -Wextra
  -Wpedantic
)
set_target_properties(cpp-app2 PROPERTIES
  CXX_EXTENSIONS OFF
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED ON
)
target_link_libraries(cpp-app2 PRIVATE
  thesis::c-lib1
)
install(
  TARGETS cpp-app2
  EXPORT cpp-app2
)

if(EMSCRIPTEN)
  return()
endif()

add_executable(cpp-app3 EXCLUDE_FROM_ALL)
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

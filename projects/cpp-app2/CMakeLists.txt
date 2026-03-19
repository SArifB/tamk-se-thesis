add_executable(cpp-app2 EXCLUDE_FROM_ALL)
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
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
)
target_link_libraries(cpp-app2 PRIVATE
  thesis::c-lib1
)

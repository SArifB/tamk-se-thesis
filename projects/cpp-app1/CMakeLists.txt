add_executable(cpp-app1 EXCLUDE_FROM_ALL)
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

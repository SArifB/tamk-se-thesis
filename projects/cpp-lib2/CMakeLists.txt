add_library(cpp-lib2 STATIC EXCLUDE_FROM_ALL)
add_library(thesis::cpp-lib2 ALIAS cpp-lib2)
target_sources(cpp-lib2
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS src
    FILES
      src/thesis/cpp-lib2.hpp
  PRIVATE
    src/thesis/cpp-lib2.cpp
)
target_compile_options(cpp-lib2 PRIVATE
  -Wall
  -Werror
  -Wextra
  -Wpedantic
)
set_target_properties(cpp-lib2 PROPERTIES
  CXX_EXTENSIONS OFF
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED ON
)

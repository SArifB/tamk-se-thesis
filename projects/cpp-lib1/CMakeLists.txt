add_library(cpp-lib1 STATIC EXCLUDE_FROM_ALL)
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
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
)

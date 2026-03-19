add_library(c-lib1 STATIC EXCLUDE_FROM_ALL)
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
  C_STANDARD 99
  C_STANDARD_REQUIRED ON
)

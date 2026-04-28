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

if(EMSCRIPTEN)
  # https://github.com/NixOS/nixpkgs/issues/497816
  set_target_properties(cpp-lib2 PROPERTIES
    CXX_SCAN_FOR_MODULES OFF
  )

  # emscripten requires executable even for library
  add_executable(cpp-lib2-emscripten)
  target_sources(cpp-lib2-emscripten PRIVATE
    src/thesis/cpp-lib2.js.cpp
  )
  target_compile_options(cpp-lib2-emscripten PRIVATE
    -Wall
    -Werror
    -Wextra
    -Wpedantic
  )
  set_target_properties(cpp-lib2-emscripten PROPERTIES
    CXX_EXTENSIONS OFF
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_SCAN_FOR_MODULES OFF
    LINK_FLAGS "-lembind --emit-tsd cpp-lib2-emscripten.d.ts --no-entry -sMODULARIZE -sEXPORT_ES6"
  )
  target_link_libraries(cpp-lib2-emscripten PRIVATE
    thesis::cpp-lib2
  )
endif()

if(SKBUILD)
  find_package(pybind11 CONFIG REQUIRED)

  pybind11_add_module(_core MODULE
    src/thesis/cpp-lib2.py.cpp
  )
  install(TARGETS _core DESTINATION ${SKBUILD_PROJECT_NAME})
  target_compile_options(_core PRIVATE
    -Wall
    -Werror
    -Wextra
    -Wpedantic
  )
  set_target_properties(_core PROPERTIES
    CXX_EXTENSIONS OFF
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
  )
  target_link_libraries(_core PRIVATE
    thesis::cpp-lib2
  )
endif()

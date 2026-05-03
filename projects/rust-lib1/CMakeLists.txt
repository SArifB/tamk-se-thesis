option(THESIS_BUILD_RUST_LIB1 "Build rust-lib1" FALSE)
if(NOT THESIS_BUILD_RUST_LIB1)
  message(STATUS "Build option not set, ignoring build (project: rust-lib1)")
  return()
endif()

if(EMSCRIPTEN)
  message(FATAL_ERROR "Emscripten system found, impossible build (project: rust-lib1)")
elseif(SKBUILD)
  message(FATAL_ERROR "SKBuild system found, impossible build (project: rust-lib1)")
endif()

include(FetchContent)
FetchContent_Declare(
  Corrosion
  GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
  GIT_TAG v0.6
)
FetchContent_MakeAvailable(Corrosion)

corrosion_import_crate(
  MANIFEST_PATH Cargo.toml
  CRATE_TYPES staticlib
  CRATES rust-lib1
)
target_sources(rust_lib1 PUBLIC
  FILE_SET HEADERS
  BASE_DIRS include
  FILES
    include/thesis/rust-lib1.h
    include/thesis/rust-lib1.hpp
)
add_library(thesis::rust-lib1 ALIAS rust_lib1)

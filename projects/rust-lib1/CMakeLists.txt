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
  FILES include/thesis/rust-lib1.h
)
add_library(thesis::rust-lib1 ALIAS rust_lib1)

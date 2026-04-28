use cbindgen::{Builder, Language};

fn main() {
  let crate_dir = std::env::var("CARGO_MANIFEST_DIR").unwrap();

  Builder::new()
    .with_crate(&crate_dir)
    .with_language(Language::C)
    .with_pragma_once(true)
    .with_no_includes()
    .with_sys_include("stdint.h")
    .with_cpp_compat(true)
    .generate()
    .expect("Unable to generate bindings")
    .write_to_file("include/thesis/rust-lib1.h");
}

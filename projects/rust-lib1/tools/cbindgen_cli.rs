use cbindgen::{Builder, Language};

fn main() {
  let crate_dir = std::env::args().nth(1).expect("crate dir");
  let out = std::env::args().nth(2).expect("output");

  Builder::new()
    .with_src("src/lib.rs")
    .with_language(Language::C)
    .with_pragma_once(true)
    .with_no_includes()
    .with_sys_include("stdint.h")
    .with_cpp_compat(true)
    .generate()
    .expect("Unable to generate bindings")
    .write_to_file(out);
}

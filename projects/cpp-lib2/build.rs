use std::env;
use std::path::PathBuf;

use bindgen::Builder;
use cmake::Config;

fn main() {
  let dst = Config::new("../..")
    .generator("Ninja")
    .define("THESIS_BUILD_CPP_LIB2", "true")
    .build_target("cpp-lib2")
    .very_verbose(true)
    .build();

  println!(
    "cargo:rustc-link-search=native={}",
    dst.join("build/projects/cpp-lib2").display()
  );
  println!("cargo:rustc-link-lib=static=cpp-lib2");

  let bindings = Builder::default()
    .header("src/thesis/cpp-lib2.hpp")
    .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
    .generate()
    .expect("Unable to generate bindings");

  let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
  bindings
    .write_to_file(out_path.join("bindings.rs"))
    .expect("Couldn't write bindings!");
}

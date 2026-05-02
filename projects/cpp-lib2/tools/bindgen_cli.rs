use std::env;

fn main() {
  let header = &env::args().nth(1).unwrap();
  let out = &env::args().nth(2).unwrap();

  let bindings = bindgen::Builder::default()
    .header(header)
    .generate()
    .expect("Unable to generate bindings");

  bindings.write_to_file(out).unwrap();
}

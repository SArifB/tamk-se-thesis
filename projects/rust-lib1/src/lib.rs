pub fn add(left: u64, right: u64) -> u64 {
  left + right
}

mod ffi {
  #[unsafe(no_mangle)]
  pub unsafe extern "C" fn thesis_rust_lib1_add(left: u64, right: u64) -> u64 {
    crate::add(left, right)
  }
}

#[cfg(feature = "wasm")]
mod ffi_js {
  #![allow(unused)]
  #![allow(nonstandard_style)]

  use wasm_bindgen::prelude::*;

  #[wasm_bindgen(start)]
  pub fn init() {
    console_error_panic_hook::set_once();
  }

  #[wasm_bindgen]
  pub fn add(left: u64, right: u64) -> u64 {
    crate::add(left, right)
  }
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn it_works() {
    let result = add(2, 2);
    assert_eq!(result, 4);
  }
}

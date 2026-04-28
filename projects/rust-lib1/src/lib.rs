pub fn add(left: u64, right: u64) -> u64 {
  left + right
}

mod ffi {
  #[unsafe(no_mangle)]
  pub unsafe extern "C" fn thesis_rust_lib1_add(left: u64, right: u64) -> u64 {
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

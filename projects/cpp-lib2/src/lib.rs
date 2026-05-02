#[cfg(not(feature = "buck2"))]
mod ffi {
  #![allow(non_upper_case_globals)]
  #![allow(non_camel_case_types)]
  #![allow(non_snake_case)]
  #![allow(unused)]

  include!(concat!(env!("OUT_DIR"), "/bindings.rs"));
}

#[cfg(feature = "buck2")]
#[path = "bindings.rs"]
mod ffi;

pub fn add(left: u64, right: u64) -> u64 {
  unsafe { ffi::thesis_cpp_lib2_add(left, right) }
}

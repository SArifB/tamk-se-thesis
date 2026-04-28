#pragma once

#include <stdint.h>

#include "rust-lib1.h"

namespace thesis {
namespace rust_lib1 {

inline uint64_t add(uint64_t left, uint64_t right) {
  return thesis_rust_lib1_add(left, right);  //
}

}  // namespace rust_lib1
}  // namespace thesis

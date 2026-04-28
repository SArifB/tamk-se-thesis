#include <print>

#include "thesis/rust-lib1.h"

constexpr auto add = thesis_rust_lib1_add;

int main() {
  std::println("add(2, 2) = {}", add(2, 2));
  return 0;
}

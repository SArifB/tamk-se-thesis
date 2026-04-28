#include <print>

#include "thesis/cpp-lib2.hpp"
#include "thesis/rust-lib1.hpp"

constexpr auto rust_add = thesis::rust_lib1::add;
constexpr auto cpp_add = thesis::cpp_lib2::add;

int main() {
  std::println("Hello, world!");
  std::println("rust_add(2, 2) = {}", rust_add(2, 2));
  std::println("cpp_add(2, 2) = {}", cpp_add(2, 2));
  return 0;
}

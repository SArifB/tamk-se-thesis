#include <iostream>

#include "thesis/cpp-app1/my-print.hpp"
#include "thesis/cpp-lib1/to-upper-appender.hpp"

namespace thesis {
namespace cpp_app1 {

auto main() -> void {
  my_print("Hello from src/thesis/cpp-app1/main.cpp");
  std::cout << cpp_lib1::ToUpperAppender{ .str = "Hello from src/thesis/cpp-app1/main.cpp" }
            << std::endl;
}

}  // namespace cpp_app1
}  // namespace thesis

int main() {
  thesis::cpp_app1::main();
  return 0;
}

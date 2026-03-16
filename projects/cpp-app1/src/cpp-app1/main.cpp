#include <cpp-lib1/to-upper-appender.hpp>
#include <iostream>

#include "cpp-app1/my-print.hpp"

int main() {
  using namespace cpp_app1;

  my_print("Hello from src/cpp-app1/main.cpp");
  std::cout << cpp_lib1::to_upper_appender("Hello from src/cpp-app1/main.cpp") << std::endl;
  return 0;
}

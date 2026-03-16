#include "cpp-app1/my-print.hpp"

#include <iomanip>
#include <iostream>
#include <string_view>

namespace cpp_app1 {

auto my_print(std::string_view str) -> void {
  std::cout << "Hello from src/cpp-app1/my-print.cpp: " << std::quoted(str) << std::endl;
}

}  // namespace cpp_app1

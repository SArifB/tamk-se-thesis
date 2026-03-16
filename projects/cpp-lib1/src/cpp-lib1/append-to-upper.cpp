#include "cpp-lib1/append-to-upper.hpp"

#include <ostream>
#include <string_view>

namespace cpp_lib1 {

auto append_to_upper(std::ostream& os, std::string_view str) -> std::ostream& {
  for (char c : str) {
    os << static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
  }
  return os;
}

}  // namespace cpp_lib1

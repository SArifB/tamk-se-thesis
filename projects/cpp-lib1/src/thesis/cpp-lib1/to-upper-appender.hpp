#pragma once
#include <ostream>
#include <string_view>

#include "thesis/cpp-lib1/append-to-upper.hpp"

namespace thesis {
namespace cpp_lib1 {

struct ToUpperAppender {
  std::string_view str;
};

inline auto operator<<(std::ostream& os, ToUpperAppender const& self) -> std::ostream& {
  return append_to_upper(os, self.str);
}

}  // namespace cpp_lib1
}  // namespace thesis
